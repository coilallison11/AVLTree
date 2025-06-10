//****************************************************************************************************
//
//         File:                        Node.h
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment #8
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Nov 5, 2021
//
//
//         This structure creates a single node for use in an AVL tree. It holds data of
//		   an unknown type as well as the node's balance factor, the address of its right child
//		   node, and the address of its left child node.
// 
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

#include <iostream>

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE value;
	int bFactor;
	Node <TYPE> * left;
	Node <TYPE> * right;

	Node ();
	Node (TYPE v, Node <TYPE> * l = nullptr, Node <TYPE> * r = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node ()
{
	value = 0;
	bFactor = 0;
	left = nullptr;
	right = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node (TYPE d, Node <TYPE> * l, Node <TYPE> * r)
{
	value = d;
	left = l;
	right = r;
	bFactor = 0;
}

//****************************************************************************************************

#endif