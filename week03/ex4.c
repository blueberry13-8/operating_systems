#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int* c = malloc(sizeof(int));
    *c = *((int*)a) + *((int*)b);
    //free(a);
    return c;
}

void* addDouble(const void* a, const void* b){
    double* c = malloc(sizeof(double));
    *c = *((double*)a) + *((double*)b);
    //free(a);
    return c;
}

void* mulInt(const void* a, const void* b){
    int* c = malloc(sizeof(int));
    *c = *((int*)a) * *((int*)b);
    //free(a);
    return c;
}

void* mulDouble(const void* a, const void* b){
    double* c = malloc(sizeof(double));
    *c = *((double*)a) * *((double*)b);
    //free(a);
    return c;
}

void* meanInt(const void* a, const void* b){
    return addInt(a, b);
}

void* meanDouble(const void* a, const void* b){
    return addDouble(a, b);
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    void* output;
    if (size==sizeof(int)){ // base is a pointer to an integer
        int* res = malloc(sizeof(int));
        *res = *((int*)initial_value);
	    for (int i = 0; i < n; i++){
            res = (int*)opr(res, base + i * sizeof(int));
        }
        if (*opr == meanInt){
            *res = (*res) / n;
        }
        //output = malloc(sizeof(int));
        output = res;
        //free(res);
	}else{ // base is a pointer to a double
        double* res = malloc(sizeof(double));
        *res = *((double*)initial_value);
        for (int i = 0; i < n; i++){
            res = (double*)opr(res, base + i * sizeof(double));
        }
        if (*opr == meanDouble){
            *res = *res / n;
        }
        //output = malloc(sizeof(double));
        output = res;
    }
	return output;
}

int main(){

        int* ints = malloc(sizeof(int)*5);
        double* doubles = malloc(sizeof(double)*5);
        
        for (int i = 0; i < 5; i++){
            ints[i] = i + 1;
            doubles[i] = 1.1 * (i + 1);
        //    printf("%lf ", doubles[i]);
        }

	// Addition
	
        int* result1a;
        int initial = 0;
        result1a = (int*)aggregate(ints, sizeof(int), 5, &initial, addInt);
        
        printf("%d\n", *result1a);

	double* result2a;
	
        double initial1 = 0;
        result2a = (double*)aggregate(doubles, sizeof(double), 5, &initial1, addDouble);
	
        printf("%f\n", *result2a);
                

	// Multiplication
	
        int* result1m;
        int initial2 = 1;
        result1m = (int*)aggregate(ints, sizeof(int), 5, &initial2, mulInt);
        
        printf("%d\n", *result1m);

	double* result2m;
	
        double initial3 = 1;
        result2m = (double*)aggregate(doubles, sizeof(double), 5, &initial3, mulDouble);
	
        printf("%f\n", *result2m);
        

	// Mean
	
        int* result1mean;
        result1mean = (int*)aggregate(ints, sizeof(int), 5, &initial, meanInt);
        
    
        printf("%d\n", *result1mean);

	double* result2mean;
	
	    result2mean = (double*)aggregate(doubles, sizeof(double), 5, &initial1, meanDouble);
	

        printf("%f\n", *result2mean);
	
        free(ints);
        free(doubles);
        free(result1a);
        free(result2a);
        free(result1m);
        free(result2m);
        free(result1mean);
        free(result2mean);

        return EXIT_SUCCESS;
}