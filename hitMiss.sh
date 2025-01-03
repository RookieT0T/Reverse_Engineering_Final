# FIFORP
# LFURP
# LIPRP
# LRURP
# MRURP
# NRURP
# RRIPRP
# BRRIPRP
# SecondChanceRP
# TreePLRURP
RP=FIFORP

prefix="./startEnd/trial_"
end=".log"
for i in {0..39}; do
    file="${prefix}${i}${end}"
    echo "File read is $file"

    start_time=$(grep "Kernel name: Some kernel" $file | awk -F: '{print $1}')
    end_time=$(grep "Completed kernel 1" $file | awk -F: '{print $1}')
    echo "Start time: $start_time, End time: $end_time"

    echo "Running test iteration $i..."
    docker run --volume $(pwd):$(pwd) -w $(pwd) amd_vega build/VEGA_X86/gem5.opt \
        --debug-flag=RubyHitMiss \
        --debug-start=$start_time --debug-end=$end_time \
        configs/example/apu_se.py \
        -n 3 --dgpu --gfx-version=gfx900 --num-compute-units=4 --cu-per-sa=4 \
        --num-gpu-complex=1 --reg-alloc-policy=dynamic --num-tccs=8 --num-dirs=64 \
        --mem-size=16GB --mem-type=HBM_2000_4H_1x64 --vreg-file-size=16384 \
        --sreg-file-size=800 --tcc-size=4MB --gpu-clock=1801MHz --ruby-clock=1000MHz \
        --vrf_lm_bus_latency=6 --mem-req-latency=69 --mem-resp-latency=69 \
        --mandatory_queue_latency=1 --max-cu-tokens=160 --max-coalesces-per-cycle=10 \
        --sqc-size=16kB --tcp-size=4MB --scalar-mem-req-latency=28 --TCP_latency=4 \
        --tcp-assoc=16 --tcp-num-banks=16 --TCC_latency=121 --tcc-assoc=16 \
        --tcc-tag-access-latency=1 --tcc-data-access-latency=1 \
        --tcp-rp=$RP --WB_L2 --tcc-rp=$RP \
        -c ./auto/testbench/trial_$i > ./hitMiss/trial_$i.log

        grep "TCC" ./hitMiss/trial_$i.log | grep "0x1" > ./hitMissFilter/trial_$i.log
done
