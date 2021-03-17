#include <string>
#include "tree.hh"
#include "tree.cc"

//adds child to parent on the specified side, only takes 'L' and 'R' as input
//if it gets a different input, or the specified side of the parent is full, returns nullptr
tree_ptr_t add_child(tree_ptr_t parent, tree_ptr_t child, std::string direction)
{
	if (direction.length() > 1)
	{
		return nullptr;
	} else 
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

}
