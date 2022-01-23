//
//  rd_dir_delete.c
//
//
//  Created by Rostyslav Druzhchenko on 23.01.2022.
//

#include <ftw.h>
#include <stdio.h>

static int unlink_cb(const char *fpath,
                     const struct stat *sb,
                     int typeflag,
                     struct FTW *ftwbuf) {
    sb++, typeflag++; ftwbuf++;
    int rv = remove(fpath);

    if (rv) {
        perror(fpath);
    }

    return rv;
}

int rd_dir_delete(const char *path) {
    return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}
