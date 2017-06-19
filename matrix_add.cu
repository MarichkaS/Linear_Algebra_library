#include <stdio.h>
#include "Matrix.h"

#define HANDLE_ERROR( err ) ( HandleError( err, __FILE__, __LINE__ ) )

static void HandleError( cudaError_t err, const char *file, int line )
{
    if (err != cudaSuccess)
      {
        printf( "%s in %s at line %d\n", cudaGetErrorString( err ),
                file, line );
        exit( EXIT_FAILURE );
    }
}



const short N = 4 ;

// CUDA Kernel for Matrix Addition
__global__ void Matrix_Addition ( const int *dev_a , const int *dev_b , int *dev_c)
{
      //Get the id of thread within a block
      unsigned short tid = threadIdx.x ;
     
      if ( tid < N ) // check the boundry condition for the threads
            dev_c [tid] = dev_a[tid] + dev_b[tid] ;

}


int main (void)
{
    int Host_a[N], Host_b[N], Host_c[N];
    //Device array
    int *dev_a , *dev_b, *dev_c ;
    //Allocate the memory on the GPU
    HANDLE_ERROR ( cudaMalloc((void **)&dev_a , N*sizeof(int) ) );
    HANDLE_ERROR ( cudaMalloc((void **)&dev_b , N*sizeof(int) ) );
    HANDLE_ERROR ( cudaMalloc((void **)&dev_c , N*sizeof(int) ) );

    //fill the Host array with random elements on the CPU
    Matrix<int> a(2, 2);
    Matrix<int> b(2, 2);
    a = {2,2,2,2};
    b = {1, 2, 3, 4};
    //cout<<a;
    //Host_a = a.matrToArr();
    //Host_b = b.matrToArr();
    int el=0;

    for (int i = 0; i < 2 ; i++ )
    {
        for(int j = 0; j< 2; j++) {
            Host_a[el] = a(i, j);
            Host_b[el] = b(i, j);
            el++;
        }
    }
   // cout<< el<< endl;

    //Copy Host array to Device array
    HANDLE_ERROR (cudaMemcpy (dev_a , Host_a , N*sizeof(int) , cudaMemcpyHostToDevice));
    HANDLE_ERROR (cudaMemcpy (dev_b , Host_b , N*sizeof(int) , cudaMemcpyHostToDevice));

    //Make a call to GPU kernel
    Matrix_Addition <<< 1, N  >>> (dev_a , dev_b , dev_c ) ;

    //Copy back to Host array from Device array
    HANDLE_ERROR (cudaMemcpy(Host_c , dev_c , N*sizeof(int) , cudaMemcpyDeviceToHost));

    for ( int i = 0; i<N; i++ )
        printf ("%d\n", Host_c[i] ) ;

    //Free the Device array memory
    cudaFree (dev_a) ;
    cudaFree (dev_b) ;
    cudaFree (dev_c) ;

    system("pause");
    return 0 ;

}
