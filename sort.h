#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algo
 *
 * @array: int
 * @size: size_t
 */
void quick_sort(int *array, size_t size);

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: int
 * @size: size_t
 */
void selection_sort(int *array, size_t size);

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: listint_t
 */
void insertion_sort_list(listint_t **list);

/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: int array
 * @size: size_t
 */
void bubble_sort(int *array, size_t size);

/**
 * _putchar - to print
 * @c: get the character
 * Return: nothing.
 */
int _putchar(char c); /**this is for putchar*/

#endif /* SORT_H */
