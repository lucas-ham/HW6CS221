#include <string>
#include "tree.hh"

tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right)
{
	tree_ptr_t newTree = new Tree();
	newTree->key_ = key; 
	newTree->value_ = value;
	newTree->left_ = left;
	newTree->right_ = right;

	return newTree;
	/*
	allocate space for a tree node
	fills it with the given parameters (has everything to describe a new node)
	children are null by default, but can have pointers to other nodes
	*/
}


void destroy_tree(tree_ptr_t tree)
{
	if (tree == nullptr)
	{
		//no value at the node, we're done with the tree
	} else
	{
		destroy_tree(tree->left_);
		destroy_tree(tree->right_);
		delete tree;
	}
	/* destroys/clears the memory space of the tree AND it's children
	easier to do this recursively?
		base case, current pointer is void, done
		otherwise delete node and run on all children
		this is the way to do it, roughly, just need to make sure commands make sense
		*/
}

std::string helper_path_to(tree_ptr_t tree, key_t key, std::string str);

std::string path_to(tree_ptr_t tree, key_t key)
{
	//need to check every possible path, until the first instance of key is found
	auto str = "";
	return helper_path_to(tree, key, str);
}

std::string helper_path_to(tree_ptr_t tree, key_t key, std::string str) 
{	
	if (tree == nullptr)
	{
		//didn't find it this time, nothing here
		str = "";
		return str;
	} else if (tree->key_ == key)
	{
		//this means we've found the path, do whatever you need to to signal that
		return str;
	} else
	{
		std::string str1 = helper_path_to(tree->left_, key, str+"L");
		std::string str2 = helper_path_to(tree->right_, key, str+"R");
		if (str1 != "") 
		{
			//picks the leftmost path to the value
			return str1;
		} else
		{
			//if the leftmost path doesn't have the value, then regardless of if the rightmost
			// does or not, return rightmost
			return str2;
		}
	}
}


tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
	if (tree == nullptr)
	{
		//end of the path, no more leaves to check, so the path doesn't exist
		return nullptr;
	} else if (path == "")
	{
		//at the end of the path AND we know the tree isn't empty
		return tree;
	} else
	{
		//not at the end of the path or an empty tree, take the next step and try again
		char first = path[0];
		switch (first)
		{
			case 'R':
			{
				tree_ptr_t newTree = tree->right_;
				path = path.substr(1);
				return node_at(newTree, path);
				break;
			}
			case 'L':
			{
				tree_ptr_t newTree = tree->left_;
				path = path.substr(1);
				return node_at(newTree, path);
				break;
			}
			default:
			{
				return nullptr;
			}
		}
	}
	/*
	follow a path from a node to the end of the given path
	not entirely sure what to do on this, need to somehow remove one char from path each time
	could do it with cases
	check path isn't empty, if it is return current tree
	seperate string into first char and rest of the string
	then switch letter, if right or left check that isn't null and call it again, 
	if not right or left return nullptr
	*/
}
