TARGET = firmware
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

CFLAGS = -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -Wall -Wextra -O0 -g -fno-builtin
LDFLAGS = -T linker.ld -nostdlib -Wl,--gc-section -Wl,-Map=$(TARGET).map 

OBJS = startup.o main.o

all: $(TARGET).bin

startup.o: startup.c
	$(CC) $(CFLAGS) -c startup.c -o startup.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

$(TARGET).elf: $(OBJS) linker.ld
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET).elf

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

disassemble: $(TARGET).elf
	$(OBJDUMP) -d -S $(TARGET).elf

clean:
	rm -rf *.o *.elf *.bin *.map
