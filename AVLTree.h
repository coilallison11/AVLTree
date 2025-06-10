//****************************************************************************************************
//
//         File:                        AVLTree.h
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment  #8
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Nov 5, 2021
//
//
//         This program creates an AVL tree where nodes can be added and restructures
//		   the tree when needed.
//
//****************************************************************************************************

#ifndef AVLTREE_H
#define AVLTREE_H

//****************************************************************************************************

#include "Node.h"
#include <iostream>

//****************************************************************************************************

template <typename TYPE>
class AVLTree
{
	private:
		Node <TYPE> * root;
		void destroy (Node <TYPE> *& r);
		void insert (Node <TYPE> *& r, const TYPE & item);
		void inorder (std::ostream & os, Node <TYPE> * r) const;
		void preorder (std::ostream & os, Node <TYPE> * r) const;
		void postorder (std::ostream & os, Node <TYPE> * r) const;
		TYPE * search (Node <TYPE> * r, const TYPE & item) const;
		int height (Node <TYPE> * r) const;
		int max (int a, int b) const;
		void rotateLeft (Node <TYPE> *& k1);
		void rotateRight (Node <TYPE> *& k1);
		int getBalance (Node <TYPE> * r) const;
		void updateBFactors (Node <TYPE> * r);

	public:
		AVLTree ();
		~AVLTree ();
		void destroy ();
		void insert (const TYPE & item);
		void inorder (std::ostream & os = std::cout) const;
		void preorder (std::ostream & os = std::cout) const;
		void postorder (std::ostream & os = std::cout) const;
		TYPE * search (const TYPE & item) const;
		int height () const;
};

//****************************************************************************************************

template <typename TYPE>
inline
AVLTree <TYPE> :: AVLTree ()
{
	root = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
inline
AVLTree <TYPE> :: ~AVLTree ()
{
	destroy (root);
}

//****************************************************************************************************

template <typename TYPE>
inline
void AVLTree <TYPE> :: destroy ()
{
	destroy (root);
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: destroy (Node <TYPE> *& r)
{
	if ( r )
	{
		destroy (r -> left);
		destroy (r -> right);
		delete r;
		r = nullptr;
	}
}

//****************************************************************************************************

template <typename TYPE>
inline
void AVLTree <TYPE> :: insert (const TYPE & item)
{
	insert (root, item);
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: insert (Node <TYPE> *& r, const TYPE & item)
{
	if ( !r )
	{
		r = new Node <TYPE> (item);
	}
	else
	{
		if ( item < r -> value )
		{
			insert (r -> left, item);
		}
		else
		{
			insert (r -> right, item);
		}
	}

	r -> bFactor = getBalance (r);

	if ( r -> bFactor > 1 )
	{
		if ( r -> left -> bFactor > 0 )
		{
			rotateRight (r);
		}
		else
		{
			rotateLeft (r -> left);
			rotateRight (r);
		}

		updateBFactors (r);
	}
	else if ( r -> bFactor < -1 )
	{
		if ( r -> right -> bFactor < 0 )
		{
			rotateLeft (r);
		}
		else
		{
			rotateRight (r -> right);
			rotateLeft (r);
		}
		updateBFactors (r);
	}
}

//****************************************************************************************************

template <typename TYPE>
inline
void AVLTree <TYPE> :: inorder (std::ostream & os) const
{
	inorder (os, root);
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: inorder (std::ostream & os, Node <TYPE> * r) const
{
	if ( r )
	{
		inorder (os, r -> left);
		os << r -> value << "  BF: " << r -> bFactor << std::endl;
		inorder (os, r -> right);
	}
}

//****************************************************************************************************

template <typename TYPE>
inline
void AVLTree <TYPE> :: preorder (std::ostream & os) const
{
	preorder (os, root);
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: preorder (std::ostream & os, Node <TYPE> * r) const
{
	if ( r )
	{
		os << r -> value << "  BF: " << r -> bFactor << std::endl;
		preorder (os, r -> left);
		preorder (os, r -> right);
	}
}

//****************************************************************************************************

template <typename TYPE>
inline
void AVLTree <TYPE> :: postorder (std::ostream & os) const
{
	postorder (os, root);
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: postorder (std::ostream & os, Node <TYPE> * r) const
{
	if ( r )
	{
		postorder (os, r -> left);
		postorder (os, r -> right);
		os << r -> value << "  BF: " << r -> bFactor << std::endl;
	}
}

//****************************************************************************************************

template <typename TYPE>
inline
TYPE * AVLTree <TYPE> :: search (const TYPE & item) const
{
	return search (root, item);
}

//****************************************************************************************************

template <typename TYPE>
TYPE * AVLTree <TYPE> :: search (Node <TYPE> * r, const TYPE & item) const
{
	TYPE * result = nullptr;

	if ( r )
	{
		if ( item < r -> value )
		{
			result = search (r -> left, item);
		}
		else if ( item > r -> value )
		{
			result = search (r -> right, item);
		}
		else
		{
			result = &( r -> value );
		}
	}

	return result;
}

//****************************************************************************************************

template <typename TYPE>
inline
int AVLTree <TYPE> :: height () const
{
	return height (root);
}

//****************************************************************************************************

template <typename TYPE>
int AVLTree <TYPE> :: height (Node <TYPE> * r) const
{
	if ( ! r )
	{
		return 0;
	}
	else
	{
		return 1 + max (height (r -> left), height (r -> right));
	}
}

//****************************************************************************************************

template <typename TYPE>
int AVLTree <TYPE> :: max (int a, int b) const
{
	int result;

	if ( a > b )
	{
		result = a;
	}
	else
	{
		result = b;
	}

	return result;
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: rotateLeft (Node <TYPE> *& k1)
{
	Node <TYPE> * k2 = k1 -> right;
	k1 -> right = k2 -> left;
	k2 -> left = k1;
	k1 = k2;
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: rotateRight (Node <TYPE> *& k1)
{
	Node <TYPE> * k2 = k1 -> left;
	k1 -> left = k2 -> right;
	k2 -> right = k1;
	k1 = k2;
}

//****************************************************************************************************

template <typename TYPE>
int AVLTree <TYPE> :: getBalance (Node <TYPE> * r) const
{
	int balance;

	if ( !r )
	{
		balance = 0;
	}
	else
	{
		balance = height (r -> left) - height (r -> right);
	}

	return balance;
}

//****************************************************************************************************

template <typename TYPE>
void AVLTree <TYPE> :: updateBFactors (Node <TYPE> * r)
{
	if ( r )
	{
		r -> bFactor = getBalance (r);
		updateBFactors (r -> left);
		updateBFactors (r -> right);
	}
}

//****************************************************************************************************

#endif