//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#ifndef RDLOG_RD_FILESYSTEM_H
#define RDLOG_RD_FILESYSTEM_H

bool rd_file_exists(char *path);
bool rd_is_directory(char *path);
void rd_create_dir(char *dir);

#endif //RDLOG_RD_FILESYSTEM_H
