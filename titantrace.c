#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// don't read this, it's boring 🥱
typedef struct { char n[1024]; long b; } B; 
typedef struct { long ms; long ml; B l[5]; } S;

// ye wala shift karta hai 🏎️
void sarp(S* s, int i) {
    int j = 4;
    while (j > i) {
        s->l[j] = s->l[j-1];
        j--;
    }
}

// boro ache ki na? 🧐
void check_boro(S* s, const char* n, long b) {
    int i = 0;
    while (i < 5) {
        if (s->l[i].b >= b) {
            i++;
            continue;
        }
        sarp(s, i);
        strcpy(s->l[i].n, n);
        s->l[i].b = b;
        break;
    }
}

// line count karne wala jadu 🪄
long gunti_karo(const char* p) {
    FILE* f = fopen(p, "r");
    if (!f) { return 0; } // OPPS 🙈

    long c = 0;
    char b[1024];
    while (fgets(b, sizeof(b), f)) {
        c++;
    }
                  fclose(f);
    return c;
}

// rasta bhatakna 🧭
void bhatakna(const char* base, S* s) {
    DIR* dr = opendir(base);
    if (!dr) { return; } // khala khatam 👋

    struct dirent* en;
    while ((en = readdir(dr)) != NULL) {
        if (strcmp(en->d_name, ".") == 0) continue;
           if (strcmp(en->d_name, "..") == 0) continue;

        char path[2048];
        snprintf(path, sizeof(path), "%s/%s", base, en->d_name);

        struct stat st;
        if (stat(path, &st) == -1) continue;

        // is it a ghor? 🏠
        if (S_ISDIR(st.st_mode)) {
            bhatakna(path, s);
            continue;
        }

        // is it a patra? 📄
        if (S_ISREG(st.st_mode)) {
            s->ms += st.st_size;
            s->ml += gunti_karo(path);
            check_boro(s, path, st.st_size);
        }
    }
    closedir(dr);
}

// prints everything 🖨️
void dekhao(S* s) {
    printf("\n--- TitanTrace Report ---\n");
    printf("Mot Size: %ld bytes\n", s->ms);
    printf("Mot Lines: %ld\n", s->ml);
    printf("\nBoro Files:\n");
    
    int k = 0;
    while (k < 5) {
        if (strlen(s->l[k].n) <= 0) {
            k++;
            continue; 
        }
        printf("%d. %s (%ld bytes)\n", k + 1, s->l[k].n, s->l[k].b);
        k++;
    }
}

int main(int argc, char* argv[]) {
    // STARTING... 🚀
    if (argc < 2) {
    printf("Usage: %s <rasta>\n", argv[0]);
    return 1;
    }

    S* x = (S*)malloc(sizeof(S));
    memset(x, 0, sizeof(S));

    bhatakna(argv[1], x);
    dekhao(x);

    free(x);
    return 0; // done dana dan 🕺
}
