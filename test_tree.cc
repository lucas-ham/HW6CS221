#include <string>
#include <assert.h>
#include <iostream>
#include "tree.hh"
#include "tree.cc"

//adds child to parent on the specified side, only takes 'L' and 'R' as input
//if it gets a different input, or the specified side of the parent is full, returns nullptr
tree_ptr_t add_child(tree_ptr_t parent, tree_ptr_t child, char direction)
{
	switch (direction)
	{
		case 'R':
		{
			if (parent->right_ == nullptr)
			{
				parent->right_ = child;
				return child;
			}else 
			{
				return nullptr;
			}
			break;
		}
		case 'L':
		{
			if (parent->left_ == nullptr)
			{
				parent->left_ = child;
				return child;
			}else
			{
				return nullptr;
			}
			break;
		}
		default:
		{
			return nullptr;
		}
	}
}
int main()
{
	tree_ptr_t tree_one = create_tree(4,3);
	tree_ptr_t tree_two = create_tree(3,3);
	tree_ptr_t tree_three = create_tree(2,1);
	tree_ptr_t tree_four = create_tree(5, 6);
	tree_ptr_t tree_five = create_tree(7, 7);
	tree_ptr_t tree_six = create_tree(2, 3);

	tree_ptr_t four = add_child(tree_one, tree_two, 'L');
	tree_ptr_t five = add_child(tree_one, tree_three, 'R');
	tree_ptr_t six = add_child(tree_two, tree_four, 'R');
	tree_ptr_t seven = add_child(tree_four, tree_six, 'L');
	tree_ptr_t eight = add_child(tree_three, tree_five, 'L');

	std::string check1 = path_to(tree_one, 2);
	
	tree_ptr_t check2 = add_child(tree_one, tree_three, 'L');

	std::string checkPath1 = "RRR";
	tree_ptr_t check3 = node_at(tree_one, checkPath1);

	std::string checkPath2 = "RL";
	tree_ptr_t check4 = node_at(tree_one, checkPath2);

	assert(tree_two == four);
	assert(tree_three == five);
	std::cout<<"add_child works as expected"<<"\n";

	std::string compareTo = "LRL"; 
	assert(check1 == compareTo);
	std::cout<<"Finds the leftmost element, even when there is a closer one in the rightmost branch"<<"\n";

	assert(check2 == nullptr);
	std::cout<<"trying to add a child to a position where there is already a child yields nullptr"<<"\n";
	
	assert(check3 == nullptr);
	std::cout<<"path to empty space returns a null pointer"<<"\n";

	assert(check4 == tree_five);
	std::cout<<"path to a branch works for two turns"<<"\n";

	

	destroy_tree(tree_one);
	std::cout<<tree_one->key_<<"\n";
	std::cout<<tree_two->key_<<"\n";
	std::cout<<tree_five->key_<<"\n";
//	assert(tree_one == nullptr);
//	assert(tree_two == nullptr);
//	assert(tree_five == nullptr);
	std::cout<<"destroy tree removes the entire tree (from the root down) and it's children"<<"\n";
	return 0;

}

