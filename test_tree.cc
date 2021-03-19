#include <string>
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
	tree_ptr_t one = create_tree(4,3);
	tree_ptr_t two = create_tree(3,3);
	tree_ptr_t three = create_tree(2,1);

	tree_ptr_t four = add_child(one, two, 'L');
	tree_ptr_t five = add_child(one, three, 'R');

	std::string check1 = path_to(one, 2);
	
	tree_ptr_t check2 = add_child(one, three, 'L');

	return 0;
}

