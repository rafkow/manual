create disk image
  dd
    create backup
      sudo dd if=/dev/mmcblk0 of=~/raspbian_backup.img
    restore backup
      sudo dd if=~/raspbian_backup.img of=/dev/mmcblk0


properties weigth folders:
      du --max-depth=1 -h
