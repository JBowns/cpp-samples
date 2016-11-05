#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

void print_list(int node, std::vector<int>& list) {
	if (node != 0)
		std::cout << "Node " << node << " is linked to node ";
	for (auto i = list.begin(); i != list.end(); ++i) {
		std::cout << (*i) << ", ";
	}
}

struct Node {

	Node(int node) : _node(node)
	{}

	void addLink(Node* ptr)	{
		_containingNodes.push_back(ptr);
	}

	std::vector<int> getList() {
		std::vector<int> list;
		std::for_each(_containingNodes.begin(), _containingNodes.end(), [&](Node* ptr) {
			list.push_back(ptr->_node);
		});
		return list;
	}

	bool contains(int node) {
		return std::count_if(_containingNodes.begin(), _containingNodes.end(), [node](Node* ptr) -> bool {return ptr->_node == node; }) != 0;
	}

	int _node;
	std::vector<Node*> _containingNodes;

};

class DirectedGraph {

public:

	~DirectedGraph() {
		for (auto i = _container.begin(); i != _container.end(); ++i) {
			delete (*i);
		}
	}

	void addNode(int node) {
		if (contains(node)) {
			throw "this number is already taken";
		} else {
			_container.push_back(new Node(node));
		}
	}

	void addLink(int node1, int node2) {
		if (contains(node1) && contains(node2)) {
			Node* ptr_node1 = find(node1);
			Node* ptr_node2 = find(node2);
			ptr_node1->addLink(ptr_node2);
		} else {
			throw "one or more of these nodes don't exist";
		}
	}

	std::vector<int> nextNodes(int node) {
		std::vector<int> list;
		if (contains(node)) {
			Node* ptr_node = find(node);
			list = ptr_node->getList();
		} else {
			throw "this node doesn't exist";
		}
		return list;
	}

	// Iterate across a list
	int nextNodes_rec(int node1, int node2, std::vector<int>& list, std::vector<std::vector<int>>& vec) {

		Node* ptr_node = find(node1);
		std::vector<int> nodes = ptr_node->getList();

		if (nodes.size() == 1) {
			list.push_back(nodes.at(0));
		} else {
			for (auto i = nodes.begin(); i != nodes.end(); ++i) {
				if ((*i) == node2) {
					list.push_back((*i));
					vec.push_back(list);
					list.clear();
					return (*i);
				} else {
					list.push_back((*i));
					int n = nextNodes_rec(*i, node2, list, vec);
					if (n != node2 && n != 0) {
						list.push_back(n);
					}
				}
			}
		}
	}

	void getRoutes(int node1, int node2) {
		std::vector<int> list;
		list.push_back(node1);
		nextNodes_rec(node1, node2, list, _vec);
	}

	void countNo() {
		for (auto i = _vec.begin(); i != _vec.end(); ++i) {
			std::cout << "size:" << (*i).size() << std::endl;
			print_list(0, (*i));
			std::cout << std::endl;
		}
	}

private:

	bool contains(int node) {
		return std::count_if(_container.begin(), _container.end(), [node](Node* ptr) -> bool {return ptr->_node == node; }) != 0;
	}

	Node* find(int node) {
		Node* found = nullptr;
		std::for_each(_container.begin(), _container.end(), [&](Node* ptr) {
			if (ptr->_node == node) {
				found = ptr;
			}
		});
		return found;
	}

	std::vector<std::vector<int>> _vec;
	std::vector<Node*> _container;

};


int main() {

	DirectedGraph dg;

	for (int i = 1; i <= 13; ++i) {
		dg.addNode(i);
	}

	dg.addLink(1, 2);
	dg.addLink(1, 6);
	dg.addLink(2, 3);
	dg.addLink(2, 9);
	dg.addLink(3, 4);
	dg.addLink(4, 5);
	dg.addLink(4, 12);
	dg.addLink(6, 7);
	dg.addLink(7, 8);
	dg.addLink(8, 9);
	dg.addLink(9, 4);
	dg.addLink(9, 10);
	dg.addLink(10, 11);
	dg.addLink(11, 12);
	dg.addLink(12, 13);

	int node = 9;
	print_list(node, dg.nextNodes(node));

	std::cout << std::endl;

	dg.getRoutes(1, 5);

	dg.countNo();

	while (!_kbhit());
	return 0;
}
