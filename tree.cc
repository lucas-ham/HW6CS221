#include <string>

int create_tree(const key_t& key, const value_t$ value, tree_ptr_t left = nullptr, tree_ptr_t right = nullptr)
{
	//allocate space for a tree node
	//fills it with the given parameters (has everything to describe a new node)
	//children are null by default, but can have pointers to other nodes
}


void destroy_tree(tree_ptr_t tree)
{
	if (tree == nullptr)
	{
		break;
	} else
	{
		//delete mem space for current tree
		destroy_tree(tree.left);
		destroy_tree(tree.right);
	}
	//destroys/clears the memory space of the tree AND it's children
	//easier to do this recursively?
		//base case, current pointer is void, done
		//otherwise delete node and run on all children
		//this is the way to do it, roughly, just need to make sure commands make sense
}

std::string path_to(tree_ptr_t tree, key_t key)
{
	//need to check every possible path, until the first instance of key is found
	//recursion is your friend here too
	auto str = ""
	return helper_path_to(tree, key, str);
}	
std::string helper_path_to(tree_ptr_t tree, key_t key, std::string str = "")
{	
	if (tree == nullptr)
	{
		//didn't find it this time, nothing here
		char str = "-";
		return str;
	} else if (tree.key == key)
	{
		//this means we've found the path, do whatever you need to to signal that
		return str;
	} else
	{
		helper_path_to(tree.left, key_t key, str+"L");
		helper_path_to(tree.right, key_t key, str+"R");
	}
}


tree_ptr_t node_at(tree_ptr_t tree, std:string path)
{
	//follow a path from a node to the end of the given path
	//not entirely sure what to do on this, need to somehow remove one char from path each time
	//could do it with cases
	//check path isn't empty, if it is return current tree
	//seperate string into first char and rest of the string
	//then switch letter, if right or left check that isn't null and call it again, 
	//if not right or left return nullptr
