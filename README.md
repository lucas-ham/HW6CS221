create_tree()
	This function simply allocates new memory for a tree type object and then fills it with the specified information
	This is a simple function, it just puts information where it should be

destroy_tree()
	This function works recursively to clear the memory stored in each tree
	First, it checks the base case (that the tree pointer is the null pointer)
	Then, it runs itself on the current tree's left child and right child
	Once the children have been destroyed, the function destroys the current tree as well
	Doing this recursively ensured that it would get all the children and not miss any since every branch is followed to a null pointer

path_to()
	I chose to use another function called "helper_path_to()" to create this function since it allowed for easier recursion
	Path_to simply initializes a string to an empty string and then returns the value of helper_path_to

	helper_path_to()
		This function does the real work of path to, and it does it recursively
		first, it checks one of the base cases which is a nullpointer
		Next, it checks if the current node's key is the key we are searching for
		If those checks fail, it runs itself on the left and right children of the current tree
			This is where the string is used, either an 'L' or 'R' is added to the end of the string when this function is called
			This all could have been written without the helper function by simply calling the function until a base case was reached and adding strings together
			Doing it with a helper function just made that process easier to track since the string is included
		Next, the function checks if the leftmost path_to returned a non-empty string (meaning it found a match)
		if the leftmost didn't find a match, it returns the rightmost
			it returns the rightmost since the leftmost is guarenteed to not have a result, so even if the rightmost doesn't the result will still be the same


node_at()
	This function also works recursively similarly to the past few functions
	First, it checks the base case that there is no tree at the current node
	Next, it checks the other base case that the string is empty (which means we have no more steps to take)
		If this case is met, it returns the current tree
	If the first two conditions are not met, it takes the next character in the path 
	Using the next character in the path, it determines which direction to go (if a direction is possible) and moves that way before calling itself again

