Commands:

qemu-system-arm -M stm32vldiscovery -kernel firmware.bin -S -gdb tcp::1234 -nographic

target remote localhost:1234

gdb-multiarch firmware.elf

ps -ef | grep qemu-system-arm
