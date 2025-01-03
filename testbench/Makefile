
HIPOPTS = --amdgpu-target=gfx900,gfx906 --save-temps

HIP_PATH ?= /opt/rocm/hip

CC := $(HIP_PATH)/bin/hipcc

release:
	$(CC) $(HIPOPTS) trial_0.cpp -o trial_0 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_1.cpp -o trial_1 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_2.cpp -o trial_2 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_3.cpp -o trial_3 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_4.cpp -o trial_4 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_5.cpp -o trial_5 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_6.cpp -o trial_6 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_7.cpp -o trial_7 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_8.cpp -o trial_8 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_9.cpp -o trial_9 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_10.cpp -o trial_10 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_11.cpp -o trial_11 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_12.cpp -o trial_12 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_13.cpp -o trial_13 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_14.cpp -o trial_14 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_15.cpp -o trial_15 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_16.cpp -o trial_16 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_17.cpp -o trial_17 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_18.cpp -o trial_18 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_19.cpp -o trial_19 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_20.cpp -o trial_20 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_21.cpp -o trial_21 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_22.cpp -o trial_22 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_23.cpp -o trial_23 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_24.cpp -o trial_24 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_25.cpp -o trial_25 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_26.cpp -o trial_26 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_27.cpp -o trial_27 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_28.cpp -o trial_28 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_29.cpp -o trial_29 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_30.cpp -o trial_30 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_31.cpp -o trial_31 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_32.cpp -o trial_32 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_33.cpp -o trial_33 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_34.cpp -o trial_34 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_35.cpp -o trial_35 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_36.cpp -o trial_36 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_37.cpp -o trial_37 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_38.cpp -o trial_38 $(CFLAGS) $(LDFLAGS)
	$(CC) $(HIPOPTS) trial_39.cpp -o trial_39 $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o *~ $(EXE)

run:
	./$(EXE)

profile:
	rocprof ./$(EXE)

events:
	rocprof --events elapsed_cycles_sm ./$(EXE)
