%include "../Emulator/vm.inc"

; assign args to registers
vset r10, 0xA   ; new line sign
vset r11, 0x30  ; 48 - the first number in ASCII


vset r2, 0x0
vset r3, 0x0

load_first_number:
    vinb 0x20, r4

    vcmp r4, r0     ; check if not new line sign
    vjz load_second_number

    vsub r4, r11    ; convert to number, not ascii code

    vmul r2, r10
    vadd r2, r4

load_second_number:
    vinb 0x20, r5

    vcmp r5, r0     ; check if not new line sign
    vjz end_of_numbers_reading

    vsub r5, r11    ; convert to number, not ascii code

    vmul r3, r10
    vadd r3, r5

end_of_numbers_reading:

    vadd r2, r3
    voutb 0x20, r2

    voff