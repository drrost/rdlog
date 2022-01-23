//
//  rd_todo.h
//
//
//  Created by Rostyslav Druzhchenko on 15.01.2022.
//

#ifndef __RND_H__
#define __RND_H__

#include <stdbool.h>

// TODO: Move to rdlib

// String
//
bool rd_str_has_suffix(const char *s, const char *suffix);
char *rd_sprintf(const char *f, ...);

// Files & dirs
//
int rd_dir_create(const char *path); // And delete rd_create_dir there.
int rd_dir_delete(const char *path);

#endif /* __RND_H__ */
