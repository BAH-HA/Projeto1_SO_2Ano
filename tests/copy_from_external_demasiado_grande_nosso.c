#include "fs/operations.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {

    char *str_ext_file_1 = "Teste de copia de arquivo externo para o nosso sistema de arquivos.";
    char *path_copied_file_1 = "/f1";
    char *path_src_1 = "Nossos_testes/ficheiro_a_copiar_teste.txt";
    
    char buffer[10];

    assert(tfs_init(NULL) != -1);

    int f;
    ssize_t r;

    f = tfs_copy_from_external_fs(path_src_1, path_copied_file_1);
    assert(f != -1);

    f = tfs_open(path_copied_file_1, TFS_O_CREAT);
    assert(f != -1);

    r = tfs_read(f, buffer, sizeof(buffer) - 1);
    assert(r == strlen(str_ext_file_1));
    assert(!memcmp(buffer, str_ext_file_1, strlen(str_ext_file_1)));

    printf("Successful test.\n");

    //test if the file has more than the block size
    
    return 0;
}
