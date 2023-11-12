/*
 * File: general.h
 * Desc: general functionalities that can be used in all other files
 *       in the project.
 * Author: Hossein Khosravi
 */

#ifndef GENERAL_H
#define GENERAL_H

/**
 * Check if a pointer is NULL or not.
 * If it's not NULL, call free on it.
 */
#define check_then_free(p) if ((p)) free((p))


/**
 * Check NULL pointer (mainly used in `if` statements)
 */
#define is_null(p) (!(p))

#endif // GENERAL_H
