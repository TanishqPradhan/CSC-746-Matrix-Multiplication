const char* dgemm_desc = "Blocked dgemm.";

/* This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. */
void square_dgemm_blocked(int n, int block_size, double* A, double* B, double* C) 
{
   // insert your code here
   
   for(int x = 0; x<n; x += block_size){
   	for(int y = 0; y<n; y += block_size){
   		for(int z = 0; z<n; z += block_size){
   			for(int i = x; i< x + block_size ; i++){
   				for(int j = y; j< y + block_size; j++){
   					for(int k = z; k< z + block_size; k++){
   						C[i + j*n] += A[i + k*n] * B[k + j*n];
   					}
   				}
   			}
   		}
   	}
   }
}
