
#include "hip/hip_runtime.h"
#define HCC_ENABLE_PRINTF
#include <stdio.h>
#include <stdlib.h>

#define CACHE_ENTRIES 4194304

// kernel code
// Access pattern: c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11, c_12, c_13, c_14, c_15, c_12, c_2, c_13, c_7, c_6, c_11, c_8, c_7, c_1, c_8, c_9, c_2, c_4, c_8, c_8, c_3, c_2, c_0, c_11, c_8, c_15, c_12, c_15, c_5, c_14, c_14, c_9, c_14, c_15, c_10, c_6, c_6, c_12, c_6, c_13, c_12, c_0, c_15, c_11, c_3, c_14, c_15, c_14, c_6
// Access count: 60

__global__ void kernel(int * arr) {
    uint64_t a = 0, b = 0, c = 0;
    
    asm volatile(
        "s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"buffer_wbinvl1\n\t" 
		"flat_load_dwordx2 %[out0], %[in1] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out2], %[in3] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out4], %[in5] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out6], %[in7] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out8], %[in9] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out10], %[in11] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out12], %[in13] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out14], %[in15] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out16], %[in17] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out18], %[in19] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out20], %[in21] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out22], %[in23] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out24], %[in25] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out26], %[in27] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out28], %[in29] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out30], %[in31] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out32], %[in33] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out34], %[in35] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out36], %[in37] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out38], %[in39] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"s_nop 0\n\t"
        : [out0]"=v"(a), [out2]"=v"(a), [out4]"=v"(a), [out6]"=v"(a), [out8]"=v"(a), [out10]"=v"(a), [out12]"=v"(a), [out14]"=v"(a), [out16]"=v"(a), [out18]"=v"(a), [out20]"=v"(a), [out22]"=v"(a), [out24]"=v"(a), [out26]"=v"(a), [out28]"=v"(a), [out30]"=v"(a), [out32]"=v"(a), [out34]"=v"(a), [out36]"=v"(a), [out38]"=v"(a)
        : [in1]"v"((uint64_t *)&arr[0]), [in3]"v"((uint64_t *)&arr[65536]), [in5]"v"((uint64_t *)&arr[131072]), [in7]"v"((uint64_t *)&arr[196608]), [in9]"v"((uint64_t *)&arr[262144]), [in11]"v"((uint64_t *)&arr[327680]), [in13]"v"((uint64_t *)&arr[393216]), [in15]"v"((uint64_t *)&arr[458752]), [in17]"v"((uint64_t *)&arr[524288]), [in19]"v"((uint64_t *)&arr[589824]), [in21]"v"((uint64_t *)&arr[655360]), [in23]"v"((uint64_t *)&arr[720896]), [in25]"v"((uint64_t *)&arr[786432]), [in27]"v"((uint64_t *)&arr[851968]), [in29]"v"((uint64_t *)&arr[917504]), [in31]"v"((uint64_t *)&arr[983040]), [in33]"v"((uint64_t *)&arr[786433]), [in35]"v"((uint64_t *)&arr[131073]), [in37]"v"((uint64_t *)&arr[851969]), [in39]"v"((uint64_t *)&arr[458753])
        : "memory");

    asm volatile(
        "s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"buffer_wbinvl1\n\t" 
		"flat_load_dwordx2 %[out40], %[in41] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out42], %[in43] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out44], %[in45] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out46], %[in47] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out48], %[in49] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out50], %[in51] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out52], %[in53] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out54], %[in55] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out56], %[in57] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out58], %[in59] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out60], %[in61] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out62], %[in63] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out64], %[in65] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out66], %[in67] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out68], %[in69] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out70], %[in71] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out72], %[in73] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out74], %[in75] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out76], %[in77] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out78], %[in79] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"s_nop 0\n\t"
        : [out40]"=v"(b), [out42]"=v"(b), [out44]"=v"(b), [out46]"=v"(b), [out48]"=v"(b), [out50]"=v"(b), [out52]"=v"(b), [out54]"=v"(b), [out56]"=v"(b), [out58]"=v"(b), [out60]"=v"(b), [out62]"=v"(b), [out64]"=v"(b), [out66]"=v"(b), [out68]"=v"(b), [out70]"=v"(b), [out72]"=v"(b), [out74]"=v"(b), [out76]"=v"(b), [out78]"=v"(b)
        : [in41]"v"((uint64_t *)&arr[393217]), [in43]"v"((uint64_t *)&arr[720897]), [in45]"v"((uint64_t *)&arr[524289]), [in47]"v"((uint64_t *)&arr[458754]), [in49]"v"((uint64_t *)&arr[65537]), [in51]"v"((uint64_t *)&arr[524290]), [in53]"v"((uint64_t *)&arr[589825]), [in55]"v"((uint64_t *)&arr[131074]), [in57]"v"((uint64_t *)&arr[262145]), [in59]"v"((uint64_t *)&arr[524291]), [in61]"v"((uint64_t *)&arr[524292]), [in63]"v"((uint64_t *)&arr[196609]), [in65]"v"((uint64_t *)&arr[131075]), [in67]"v"((uint64_t *)&arr[1]), [in69]"v"((uint64_t *)&arr[720898]), [in71]"v"((uint64_t *)&arr[524293]), [in73]"v"((uint64_t *)&arr[983041]), [in75]"v"((uint64_t *)&arr[786434]), [in77]"v"((uint64_t *)&arr[983042]), [in79]"v"((uint64_t *)&arr[327681])
        : "memory");

    asm volatile(
        "s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"buffer_wbinvl1\n\t" 
		"flat_load_dwordx2 %[out80], %[in81] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out82], %[in83] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out84], %[in85] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out86], %[in87] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out88], %[in89] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out90], %[in91] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out92], %[in93] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out94], %[in95] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out96], %[in97] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out98], %[in99] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out100], %[in101] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out102], %[in103] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out104], %[in105] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out106], %[in107] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out108], %[in109] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out110], %[in111] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out112], %[in113] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out114], %[in115] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out116], %[in117] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"flat_load_dwordx2 %[out118], %[in119] glc\n\t"

		"s_waitcnt vmcnt(0) & lgkmcnt(0)\n\t" 
		"s_nop 0\n\t"
        : [out80]"=v"(c), [out82]"=v"(c), [out84]"=v"(c), [out86]"=v"(c), [out88]"=v"(c), [out90]"=v"(c), [out92]"=v"(c), [out94]"=v"(c), [out96]"=v"(c), [out98]"=v"(c), [out100]"=v"(c), [out102]"=v"(c), [out104]"=v"(c), [out106]"=v"(c), [out108]"=v"(c), [out110]"=v"(c), [out112]"=v"(c), [out114]"=v"(c), [out116]"=v"(c), [out118]"=v"(c)
        : [in81]"v"((uint64_t *)&arr[917505]), [in83]"v"((uint64_t *)&arr[917506]), [in85]"v"((uint64_t *)&arr[589826]), [in87]"v"((uint64_t *)&arr[917507]), [in89]"v"((uint64_t *)&arr[983043]), [in91]"v"((uint64_t *)&arr[655361]), [in93]"v"((uint64_t *)&arr[393218]), [in95]"v"((uint64_t *)&arr[393219]), [in97]"v"((uint64_t *)&arr[786435]), [in99]"v"((uint64_t *)&arr[393220]), [in101]"v"((uint64_t *)&arr[851970]), [in103]"v"((uint64_t *)&arr[786436]), [in105]"v"((uint64_t *)&arr[2]), [in107]"v"((uint64_t *)&arr[983044]), [in109]"v"((uint64_t *)&arr[720899]), [in111]"v"((uint64_t *)&arr[196610]), [in113]"v"((uint64_t *)&arr[917508]), [in115]"v"((uint64_t *)&arr[983045]), [in117]"v"((uint64_t *)&arr[917509]), [in119]"v"((uint64_t *)&arr[393221])
        : "memory");
}

int main(){
    int *arr = (int *)calloc(sizeof(int), CACHE_ENTRIES);
    int *arr_g;

    hipMallocManaged(&arr_g, CACHE_ENTRIES*sizeof(int));
    hipMemcpy(arr_g, arr, CACHE_ENTRIES*sizeof(int), hipMemcpyHostToDevice);

    hipLaunchKernelGGL(kernel, dim3(1), dim3(1), 0, 0, arr_g);

    hipFree(arr_g);
    free(arr);
    return 0;
}
    