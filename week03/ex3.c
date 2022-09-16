#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//<WRITE YOUR CODE HERE>

int number_files = 0;

struct File{
    int id;
    char name[63];
    long int size;
    char data[1024];
    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;
    char path[2048];
    struct File* files[256];
    struct Directory* directories[8];
};

typedef struct Directory Directory;
typedef struct File File;


// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2, char* name); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

void create_dir(Directory* dir, char* path){
    strcpy(dir->path, path);
    dir->nd = 0;
    dir->nf = 0;
}

int main(){
    
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";
    
    Directory home, bin, root;

    create_dir(&root, "/");
    create_dir(&bin, "1");
    create_dir(&home, "1");
    
    add_dir(&home, &root, "home");
    add_dir(&bin, &root, "bin");    

    File bash, ex31, ex32;
    strcpy(bash.name, "bash");
    strcpy(ex31.name, "ex3_1.c");
    strcpy(ex32.name, "ex3_2.c");
    
    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);

    add_to_file(&ex31, "int printf(const char * format, ...);");
    add_to_file(&ex32, "//This is a comment in C language");
    add_to_file(&bash, "Bourne Again Shell!!");
    
    append_to_file(&ex31, "int main(){printf(”Hello World!”)}");

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);
   
    return 0;
}

void show_dir(Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++){
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");
    
    for (int i = 0; i < dir->nd; i++){
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

void show_file(File *file){
    printf("%s ", file->name);
}

void show_file_detailed(File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}

void add_to_file(File *file, const char * content) {
    if (!file){
        printf("add_to_file ERROR: such file is not created\n");
        return;
    }
    file->size = strlen(content);
    strcpy(file->data, content);
}

void append_to_file(File *file, const char * content) {
	if (!file){
        printf("append_to_file ERROR: such file is not created\n");
        return;
    }
    file->size += strlen(content);
    strcat(file->data, content);
}

void pwd_file(File * file) {
    printf("%s/%s", file->directory->path, file->name);
}

void add_file(File* file, Directory *dir) {
    if (!file || !dir){
        printf("add_file ERROR: such file or directory is not created\n");
        return;
    }
    dir->files[dir->nf] = file;
    dir->nf++;
    file->id = number_files++;
    file->directory = dir;
}

void add_dir(Directory *dir1, Directory *dir2, char* name){
	if (dir1 && dir2){
		dir2->directories[dir2->nd] = dir1;
		dir2->nd++;
        strcpy(dir1->path, dir2->path);
        strcat(dir1->path, name);
	}
}