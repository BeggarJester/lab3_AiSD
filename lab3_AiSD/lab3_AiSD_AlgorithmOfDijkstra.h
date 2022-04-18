#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;

template <typename first_typename, typename second_typename>

class CustomPair {
	first_typename first;
	second_typename second;

public:

	// CustomPair class Constructor
	CustomPair() {
	}

	// CustomPair class Constructor
	CustomPair(const first_typename firstPatameter, const second_typename secondParameter) {
	first = firstPatameter;
	second = secondParameter;
	}

	// return pair first value
	first_typename getFirst() {
		return first;
	}

	// return pair second value
	second_typename getSecond() {
		return second;
	}

};

template <typename first_typename>

class DoubleList {

private:

	size_t size; // size of DoubleList

    class Node {
    public:
        first_typename value; // value of element
        Node* next; // pointer to the next element
        Node* prev; // pointer to the previous element
    };

public:

	Node* head; // pointer to the begin of DoubleList
	Node* tail; // pointer to the end of DoubleList

    // Constructor without value
    DoubleList() {
        head = tail = NULL;
        Node* buffer = new Node; // Create temporary node
        buffer->prev = NULL;
        buffer->next = NULL;
        //buffer->value = NULL;
		size = 0;
    }

    // Destructor
    ~DoubleList() {
        clear();
    }

    // Add element after others
    void push_back(first_typename value) {
        Node* buffer = new Node; // Create temporary node
        if (isEmpty() == 1) { // If DoubleList is empty
            buffer->value = value;
            buffer->next = tail;
            head = buffer;
            buffer->prev = NULL;
            tail = buffer;
        }
        else { // If DoubleList isn't empty
            buffer->value = value;
            buffer->next = tail->next;
            buffer->prev = tail;
            tail->next = buffer;
            tail = buffer;
        }
		size++;
    }

    // Delete the Double list
    void clear() {
        Node* buffer = head; // Create temporary node
        while (head != NULL) {
            Node* buffer = head->next;
            delete head;
            head = buffer;
        }
        tail = head;
		size = 0;
    }

    // Check the empty of Double list
    bool isEmpty() {
        bool result = false;
        if (size == NULL) result = true;
        return result;
    }

    size_t getSize() {
        return size;
    }

    bool contains(first_typename value) {
        Node * current = head;
        if (isEmpty() == 1) return false;
        if (current->value == value) return true;
		
        while(current != tail) {
             if (current->value == value) return true;
            current = current->next;
        }
		if (tail->value == value) return true;
        return false;
    }

    // Reverse the Double list
    void reverse() {
        Node* left = head, * right = head;
        while (right->next != NULL) right = right->next;
        while (left != right && left->prev != right) {
            swap(left->value, right->value);
            left = left->next;
            right = right->prev;
        }
    }

};

template <typename first_typename>

class stack
{
private:
	// class Node for stack element storage
	class Node
	{
	public:
		first_typename value;
		Node* prev;
		Node(const first_typename element) :value(element), prev(0) {}
	};
	Node* current;
	size_t size_stack;
public:
	// Consrtructor of stack
	stack() :current(0), size_stack(0) {}

	// Desrtructor of stack
	~stack()
	{
		while (current)
			pop();
	}

	// add element to the stack
	void push(const first_typename element)
	{
		Node* temp = current;
		current = new Node(element);
		current->prev = temp;
		size_stack++;
	}

	// remove top element from the stack
	void pop()
	{
		if (size_stack) {
			Node* temp = current->prev;
			delete current;
			current = temp;
			size_stack--;
		}
		else {
			throw out_of_range("stack is empty");
		}
	}

	// get the element on the top of the stack
	first_typename top()
	{
		return current->value;
	}

	// check the stack's empty
	bool empty()
	{
		return !size_stack;
	}

	// get the size of the stack
	size_t size()
	{
		return size_stack;
	}
};

template <typename first_typename>

class Linked_list {

	// class Node for Linked_list element storage
	class Node {
	public:
		first_typename data;
		Node* next;
	};

	// delete the head
	void delete_head() {
		if (head != NULL)
		{
			list_size--;
			Node* to_delete = head;
			to_delete = head;
			head = head->next;
			delete to_delete;
		}
		else
			throw out_of_range("List is empty");
	}

public:

	Node* head; // pointer to the Linked_list head
	int list_size;

	// Constructor
	Linked_list() {
		head = NULL;
		list_size = 0;
	}

	// Destructor
	~Linked_list() {
		list_size = 0;
	}

	// insert the element to the end of list
	void insert_node(first_typename data) {
		// Create the new Node.
		Node* new_node = new Node;
		new_node->data = data;
		new_node->next = NULL;
		list_size++;

		// if it is first element
		if (head == NULL) {
			head = new_node;
			return;
		}

		// else go to the end of list
		Node* current_last = head;
		while (current_last->next != NULL) {
			current_last = current_last->next;
		}
		// insert at the last
		current_last->next = new_node;
	}

	// get the head value
	first_typename get_head() {
		if (list_size != 0)
			return head->data;
		else
			throw out_of_range("List is empty");
	}

	// go to the next element of the list
	void set_next() {
		if (head != NULL)
			head = head->next;
		else
			throw out_of_range("There is not next element");
	}

	// get the list size
	int size() {
		return list_size;
	}

};

template <typename first_typename, typename second_typename>

// class CustomMap based on RBTree
class CustomMap {
private:

	// class Node for RBTree element storage
	class Node {
	public:
		first_typename key; // holds the key
		second_typename value; // holds the value
		Node* parent; // pointer to the parent
		Node* left; // pointer to left child
		Node* right; // pointer to right child
		int color; // 0 is Black, 1 is Red

		Node() {
			color = 0;
			left = nullptr;
			right = nullptr;
		}

		Node(first_typename outside_key, second_typename outside_value) {
			parent = nullptr;
			key = outside_key;
			value = outside_value;
			color = 1; // inserting node must be red
		}
	};

	Node* root;  // pointer to the root of RBTree
	Node* Nil; // pointer to the NULL

	// move moving_node to the host_node place
	void moving(Node* host_node, Node* moving_node) {
		if (host_node->parent == nullptr) {
			root = moving_node;
		}
		else if (host_node == host_node->parent->left) {
			host_node->parent->left = moving_node;
		}
		else {
			host_node->parent->right = moving_node;
		}
		moving_node->parent = host_node->parent;
	}

	// left-rotation at node current_node
	void left_rotate(Node* current_node) {
		Node* right_child = current_node->right;
		current_node->right = right_child->left;
		if (right_child->left != Nil) {
			right_child->left->parent = current_node;
		}
		right_child->parent = current_node->parent;
		if (current_node->parent == nullptr) {
			root = right_child;
		}
		else if (current_node == current_node->parent->left) {
			current_node->parent->left = right_child;
		}
		else {
			current_node->parent->right = right_child;
		}
		right_child->left = current_node;
		current_node->parent = right_child;
	}

	// right-rotation at node current_node
	void right_rotate(Node* current_node) {
		Node* left_child = current_node->left;
		current_node->left = left_child->right;
		if (left_child->right != Nil) {
			left_child->right->parent = current_node;
		}
		left_child->parent = current_node->parent;
		if (current_node->parent == nullptr) {
			root = left_child;
		}
		else if (current_node == current_node->parent->right) {
			current_node->parent->right = left_child;
		}
		else {
			current_node->parent->left = left_child;
		}
		left_child->right = current_node;
		current_node->parent = left_child;
	}

	// fix the RBTree modified by the insert operation
	void fix_after_insert(Node* x) {
		Node* uncle;
		while (x->parent->color == 1) {
			if (x->parent == x->parent->parent->right) {
				uncle = x->parent->parent->left;
				if (uncle->color == 1) {
					// parent becomes black, uncle becomes black, grandparent becomes red
					uncle->color = 0;
					x->parent->color = 0;
					x->parent->parent->color = 1;
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->left) {
						// do the right-rotation at parent of current_node
						x = x->parent;
						right_rotate(x);
					}
					x->parent->color = 0; // parent becomes black
					x->parent->parent->color = 1; // grandparent becomes red
					left_rotate(x->parent->parent); // do the left-rotation at grandparent, grandparent becomes brother of current_node
				}
			}
			else {
				uncle = x->parent->parent->right;

				if (uncle->color == 1) {
					// parent becomes black, uncle becomes black, grandparent becomes red
					uncle->color = 0;
					x->parent->color = 0;
					x->parent->parent->color = 1;
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->right) {
						// do the left-rotation at parent of current_node
						x = x->parent;
						left_rotate(x);
					}

					x->parent->color = 0; // parent becomes black
					x->parent->parent->color = 1; // grandparent becomes red
					right_rotate(x->parent->parent); // do the right-rotation at grandparent, grandparent becomes brother of current_node
				}
			}
			if (x == root) {
				break;
			}
		}
		root->color = 0; // root must be black
	}

	// fix the RBTree modified by the remove operation
	void fix_after_remove(Node* x) {
		Node* brother;
		while (x != root && x->color == 0) {
			// if brother is right brother of x
			if (x == x->parent->left) {
				brother = x->parent->right; // brother is right brother of x
				if (brother->color == 1) {
					// if x's brother color is red
					brother->color = 0;
					x->parent->color = 1;
					left_rotate(x->parent);
					brother = x->parent->right;
				}

				if (brother->left->color == 0 && brother->right->color == 0) {
					// if x's brother color is red, and both of x’s brother's children are black
					brother->color = 1;
					x = x->parent;
				}
				else {
					if (brother->right->color == 0) {
						// if x's brother color is red, x’s brother's right child is black, x’s brother's left child is red
						brother->left->color = 0;
						brother->color = 1;
						right_rotate(brother);
						brother = x->parent->right;
					}

					// if x's brother color is black, x’s brother's right child is red
					brother->color = x->parent->color;
					x->parent->color = 0;
					brother->right->color = 0;
					left_rotate(x->parent);
					x = root;
				}
			}
			// if brother is left brother of x = mirror of brother is right brother of x
			else {
				brother = x->parent->left; // brother is left brother of x
				if (brother->color == 1) {
					// if x's brother color is red
					brother->color = 0;
					x->parent->color = 1;
					right_rotate(x->parent);
					brother = x->parent->left;
				}

				if (brother->right->color == 0 && brother->left->color == 0) {
					// if x's brother color is red, and both of x’s brother's children are black
					brother->color = 1;
					x = x->parent;
				}
				else {
					if (brother->left->color == 0) {
						// if x's brother color is red, x’s brother's right child is red, x’s brother's left child is black
						brother->right->color = 0;
						brother->color = 1;
						left_rotate(brother);
						brother = x->parent->left;
					}

					// if x's brother color is black, x’s brother's left child is red
					brother->color = x->parent->color;
					x->parent->color = 0;
					brother->left->color = 0;
					right_rotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0; // root must be black
	}

	//algorithm part of find operation
	Node* find_algorithm(Node* current_node, first_typename key) {
		if (key == current_node->key) {
			return current_node;
		}

		// check that tree contains the node with looking for key
		if (current_node == Nil) {
			throw out_of_range("Couldn't find key in the RBTree");
		}

		if (key < current_node->key) {
			return find_algorithm(current_node->left, key);
		}
		return find_algorithm(current_node->right, key);
	}

	//algorithm part of contains operation
	bool contains_algorithm(Node* current_node, first_typename key) {
		if (key == current_node->key) {
			return true;
		}

		if (current_node == Nil) {
			return false;
		}

		if (key < current_node->key) {
			return contains_algorithm(current_node->left, key);
		}
		return contains_algorithm(current_node->right, key);
	}

	// record RBTree keys in stack to clear the RBTree
	void RBTree_to_stack(Node* node, stack<first_typename>& MyStack) {
		if (node != Nil) {
			MyStack.push(node->key);
			RBTree_to_stack(node->left, MyStack);
			RBTree_to_stack(node->right, MyStack);
		}
	}

	//algorithm part of get keys operation
	void get_keys_algorithm(Node* node, Linked_list<first_typename>& MyLinked_list) {
		if (node != Nil) {
			MyLinked_list.insert_node(node->key);
			get_keys_algorithm(node->left, MyLinked_list);
			get_keys_algorithm(node->right, MyLinked_list);
		}
	}

	//algorithm part of get values operation
	void get_values_algorithm(Node* node, Linked_list<second_typename>& MyLinked_list) {
		if (node != Nil) {
			MyLinked_list.insert_node(node->value);
			get_values_algorithm(node->left, MyLinked_list);
			get_values_algorithm(node->right, MyLinked_list);
		}
	}

	// helper method to print the RBTree
	void print_with_indent(Node* node, int level = 0)
	{
		if (node != Nil)
		{
			print_with_indent(node->left, level + 1);
			for (int i = 0; i < level; i++) cout << "   ";
			cout << setw(3) << node->key;
			if (node->color == 0) { cout << " (Black)" << '\n'; }
			else { cout << " (Red)" << '\n'; }
			print_with_indent(node->right, level + 1);
		}
	}

public:
	// CustomMap class Constructor 
	CustomMap() {
		Nil = new Node;
		/*Nil->color = 0;
		Nil->left = nullptr;
		Nil->right = nullptr;*/
		root = Nil;
	}

	// CustomMap class Destructor 
	~CustomMap() {
		clear();
	}

	// insert the node with user's key and value to the RBTree in its appropriate position and fix the RBTree after insertion
	void insert(first_typename key, second_typename value) {

		Node* inserting_node = new Node(key, value);
		inserting_node->left = Nil;
		inserting_node->right = Nil;

		Node* y = nullptr;
		Node* x = root;

		while (x != Nil) {
			y = x;
			if (inserting_node->key < x->key) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}

		// if y is parent of x
		inserting_node->parent = y;
		if (y == nullptr) {
			root = inserting_node;
		}
		else if (inserting_node->key < y->key) {
			y->left = inserting_node;
		}
		else {
			y->right = inserting_node;
		}

		// if inserting_node is a root node
		if (inserting_node->parent == nullptr) {
			inserting_node->color = 0;
			return;
		}

		// if the grandparent is null
		if (inserting_node->parent->parent == nullptr) {
			return;
		}

		// fix the tree
		fix_after_insert(inserting_node);
	}

	// remove the node with user's key from the RBTree and fix the RBTree after deletion
	void remove(first_typename key) {
		Node* node_to_be_deleted = Nil;
		Node* x;
		Node* y;

		// finding the node with looking for key
		node_to_be_deleted = find(key);

		y = node_to_be_deleted;
		int y_original_color = y->color; // save the node_to_be_deleted color
		if (node_to_be_deleted->left == Nil) {
			x = node_to_be_deleted->right;
			moving(node_to_be_deleted, node_to_be_deleted->right); // move x to the node_to_be_deleted place
		}
		else if (node_to_be_deleted->right == Nil) {
			x = node_to_be_deleted->left;
			moving(node_to_be_deleted, node_to_be_deleted->left); // move x to the node_to_be_deleted place
		}
		else {
			// y becomes the minimum key in node_to_be_deleted right subtree
			y = node_to_be_deleted->right;
			while (y->left != Nil) {
				y = y->left;
			}
			// save the y color
			y_original_color = y->color;
			x = y->right;
			if (y->parent == node_to_be_deleted) {
				x->parent = y;
			}
			else {
				moving(y, y->right); // move y right child to the y place
				y->right = node_to_be_deleted->right;
				y->right->parent = y;
			}

			moving(node_to_be_deleted, y); // move y to the node_to_be_deleted place
			y->left = node_to_be_deleted->left;
			y->left->parent = y;
			y->color = node_to_be_deleted->color;
		}
		delete node_to_be_deleted;

		// if y_original_color is black
		if (y_original_color == 0) {
			fix_after_remove(x);
		}
	}

	// search the node with user's key
	Node* find(first_typename key) {
		return find_algorithm(root, key);
	}

	// clear the RBTree by remove nodes step be step
	void clear() {
		stack<first_typename> MyStack;
		RBTree_to_stack(root, MyStack);
		while (MyStack.size()) {
			remove(MyStack.top());
			MyStack.pop();
		}
	}

	// return the list of RBTree keys
	Linked_list<first_typename> get_keys() {
		Linked_list<first_typename> MyLinked_list;
		get_keys_algorithm(root, MyLinked_list);
		return MyLinked_list;
	}

	// return the list of RBTree values
	Linked_list<second_typename> get_values() {
		Linked_list<second_typename> MyLinked_list;
		get_values_algorithm(root, MyLinked_list);
		return MyLinked_list;
	}

	// print the RBTree on the screen
	void print() {
		return print_with_indent(root);
	}

	bool contains(first_typename key) {
		return contains_algorithm(root, key);
	}
};

// class DijkstraGraphs
class DijkstraGraphs {

    int count_vertexes; // count of graph vertexes
	CustomMap<int, string> InverseCitiesMap; // map contains vertexes indexes
    DoubleList<CustomPair<CustomPair<string, int>, int> >* AdjacencyList; // array of Adjacency List for each vertex

	int* dist;
	int* prev;
	bool* visited;

	// calculate minimum distance in graph on this step
	int min_distance() {
		int min = INT_MAX, index = 0;
		for (int i = 0; i < count_vertexes; i++)
			if (dist[i] <= min && visited[i] == false) {
				min = dist[i];
				index = i;
			}
		return index;
	}

	// algorithm part of dijkstra search
	void dijkstra_algorithm(CustomPair<string, int> start, CustomPair<string, int> finish) {

		for (int i = 0; i < count_vertexes; i++) { visited[i] = false; };
		for (int i = 0; i < count_vertexes; i++)
			dist[i] = INT_MAX;
		dist[start.getSecond()] = 0;
		for (int i = 0; i < count_vertexes - 1; i++) {
			int minimum_distance = min_distance();
			visited[minimum_distance] = true;
			auto current = AdjacencyList[minimum_distance].head;
			while (current != NULL) {
				if (visited[current->value.getFirst().getSecond()] == false && dist[minimum_distance] != INT_MAX && dist[current->value.getFirst().getSecond()] > dist[minimum_distance] + current->value.getSecond()) {
					dist[current->value.getFirst().getSecond()] = dist[minimum_distance] + current->value.getSecond();
					prev[current->value.getFirst().getSecond()] = minimum_distance;
				}
				current = current->next;
			}
		}

	}

public:
	// DijkstraGraphs class Constructor 
    DijkstraGraphs(const int vertexes) {
        count_vertexes = vertexes;
        AdjacencyList = new DoubleList<CustomPair<CustomPair<string, int>, int> >[count_vertexes];
		dist = new int[count_vertexes];
		prev = new int[count_vertexes];
		visited = new bool[count_vertexes];
    }

	// DijkstraGraphs class Destructor 
	~DijkstraGraphs() {
		delete [] AdjacencyList;
		delete[] dist;
		delete[] prev;
		delete[] visited;
		InverseCitiesMap.~CustomMap();
	}

	// add edge to the graph
    void add_edge(CustomPair<string, int> vertex_from, CustomPair<string, int> vertex_to, int weight) {
        AdjacencyList[vertex_from.getSecond()].push_back(CustomPair<CustomPair<string, int>, int>(vertex_to, weight));
		InverseCitiesMap.insert(vertex_from.getSecond(), vertex_from.getFirst());
		InverseCitiesMap.insert(vertex_to.getSecond(), vertex_to.getFirst());
    }

	// dijkstra lowest cost og travelling
	int dijkstra_lowest_cost(CustomPair<string, int> start, CustomPair<string, int> finish) {

		dijkstra_algorithm(start, finish);
		
		// if there is not way from first city to second
		if (dist[finish.getSecond()] == INT_MAX) {
			throw invalid_argument("there is not way from first city to second");
		}
		
		return dist[finish.getSecond()];
	}

	// return the lowest cost path from first city to second and those sum cost
	string dijkstra_lowest_cost_path(CustomPair<string, int> start, CustomPair<string, int> finish) {

		dijkstra_algorithm(start, finish);

		string answer = "";

		// if there is not way from first city to second
		if (dist[finish.getSecond()] == INT_MAX) {
			return "there is not way from first city to second";
		}
		else {
			DoubleList<string> path;
			for (int v = finish.getSecond(); v != start.getSecond(); v = prev[v]) {
				path.push_back(InverseCitiesMap.find(v)->value);
			}
			path.push_back(start.getFirst());
			path.reverse();
			auto output = path.head;
			while (output != NULL) {
				answer += output->value;
				if (output != path.tail) answer += " --> ";
				output = output->next;
			}

			return answer;
		}

	}

};