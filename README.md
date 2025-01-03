# Reverse_Engineering_Final

## Files Explanation
1. **`testbench` Directory**: Contains all 40 micro-testbenches, each with 60 cache accesses.
2. **`gen.py`**: Automatically generates the `testbench` directory and the 40 micro-testbenches within it.
3. **`hitMiss.sh`**: A shell script for generating and filtering the correct TCC cache hits/misses in gem5.
4. **`startEnd.sh`**: A shell script for generating log files containing the debug start time and debug end time, which serve as internal fields for commands in `hitMiss.sh`.

---

## Setup Instructions
To set up the project, follow these steps:

1. **Clone Repository**: Clone this repository into the gem5 root directory. After cloning, all the files mentioned above will be in the directory `Reverse_Engineering_Final`.
2. **Create `auto` Directory**: In the gem5 root directory, create a new directory called `auto`.
3. **Move Files**:
   - Copy the `testbench` directory and `gen.py` from the cloned directory `Reverse_Engineering_Final` into the newly created `auto` directory.
   - Double-check:
     - From the gem5 root, you should find the `auto` directory alongside other gem5 directories like `build`, `configs`, `docs`, etc.
     - Inside the `auto` directory, you should only see the `testbench` directory and `gen.py`.
   - Copy `hitMiss.sh` and `startEnd.sh` from the cloned directory `Reverse_Engineering_Final` into the gem5 root. These two scripts should now be located alongside gem5 directories like `build`, `configs`, `docs`, etc., and the `auto` directory.
4. **Create Additional Directories**:
   - In the gem5 root directory, create three new directories:
     - `startEnd`
     - `hitMiss`
     - `hitMissFilter`
   - Note: These directory names cannot be changed. Their purpose:
     - `startEnd`: Stores log files containing the debug start time and end time for each micro-testbench.
     - `hitMiss`: Stores all cache hits/misses for each micro-testbench.
     - `hitMissFilter`: Stores filtered TCC cache hits/misses for each micro-testbench, which are the final data you need. 

---

## How to Run
1. **Update the Replacement Policy**:
   - In both `startEnd.sh` and `hitMiss.sh`, update the variable `RP` to the cache replacement policy you want to use for configuring gem5.
   - Example: To test `LFURP`, set `RP=LFURP`. The default is `RP=FIFORP`.
2. **Run Testbenches**:
   - The iterator `i` is already set to range from 0 to 39 (covering all 40 micro-testbenches): `for i in {0..39}; do`.
   - Make sure you are in the gem5 root directory and run:
     - `./startEnd.sh`: Sequentially runs all 40 testbenches to acquire their debug start time and end time.
     - After 2 or 3 testbenches have completed (i.e., their debug data is available in the `startEnd` directory), run:
       - `./hitMiss.sh`: Generates and collects cache hits/misses for each micro-testbench.
     - Note: You can overlap these steps to save time. Once some debug data is available from `startEnd.sh`, you can start running `hitMiss.sh`.
3. **Wait for Completion**.

---

## Notes
- Checking `config.ini` in the `m5out` directory is good practice for verifying the cache replacement policy you are testing.
- You can run multiple gem5 instances configured with different cache replacement policies on the same set of micro-testbenches to speed up testing.
  - **Recommended**: Run only 2 gem5 instances simultaneously to avoid overloading the shared 12-core CPU, which is shared among all research groups. Running too many gem5 instances simultaneously will slow down execution.
