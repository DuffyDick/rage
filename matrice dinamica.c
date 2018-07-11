 int i;
        int **p;
        p = (int**)malloc(riga*sizeof(int*));
        for(i = 0; i <= colonna; i++)
            p[i] = (int*) malloc(colonna*sizeof(int));
