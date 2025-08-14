/*
 * This is a collection of function for drawing
 * shapes inside the board.
 *
 * Every function takes the coordinates of the 
 * upper left cell of the lowest rectangle containing
 * the shape.
 */

#pragma once
#include "board.h"

/* insert a glider into the board at position i, j
 *
 *      ()
 *        ()
 *    ()()()
 *
 */
void glider(Board* b, size_t i, size_t j);


/* insert a blinker into the board at position i, j
 *
 *      ()
 *      ()
 *      ()
 *
 */
void blinker(Board* b, size_t i, size_t j);


/* insert a R-pentomimo into the board at position i, j
 *
 *      ()()
 *    ()()
 *      ()
 *
 */
void r_pentomino(Board* b, size_t i, size_t j);

/* insert a Diehard into the board at position i, j
 *
 *                ()
 *    ()() 
 *      ()      ()()()
 *
 */
void diehard(Board* b, size_t i, size_t j);
