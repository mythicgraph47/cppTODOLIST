#!/usr/bin/env python3
import os
import sys
import time


def clear_screen():
    # 'clear' is the standard Linux command to wipe the terminal screen
    os.system("clear")


def show_system_info():
    clear_screen()
    print("=== Fedora System Summary ===\n")

    # Uses standard Linux commands directly
    print("--- Host & Kernel Info ---")
    os.system("hostnamectl")

    print("\n--- Memory Usage ---")
    os.system("free -h")

    input("\nPress Enter to go back to the menu...")


def check_disk_space():
    clear_screen()
    print("=== Storage Space ===\n")

    # 'df -h' shows drive space in human-readable sizes (GB/MB)
    # '-x tmpfs' hides temporary system drives to keep it clean
    os.system("df -h -x tmpfs -x devtmpfs")

    input("\nPress Enter to go back to the menu...")


def update_fedora():
    clear_screen()
    print("=== Fedora System Update ===\n")
    print("This will check Fedora's repositories using 'dnf' for updates.\n")

    confirm = input("Do you want to run updates now? (y/N): ").strip().lower()
    if confirm == "y":
        print("\n[!] Fedora may ask for your password to run 'sudo dnf upgrade'...\n")
        # 'sudo dnf upgrade' is the standard way to update Fedora packages
        os.system("sudo dnf upgrade")
    else:
        print("Update canceled.")

    input("\nPress Enter to go back to the menu...")


def clean_dnf_cache():
    clear_screen()
    print("=== Clean Up Package Cache ===\n")
    print("Over time, DNF saves downloaded packages. Clearing this frees up space.\n")

    confirm = input("Clean DNF cache? (y/N): ").strip().lower()
    if confirm == "y":
        os.system("sudo dnf clean all")
        print("\nDone! Cache cleared.")

    input("\nPress Enter to go back to the menu...")


def main():
    while True:
        clear_screen()
        print(
            """
┌───────────────────────────────────────────┐
│        FEDORA EASY HELPER TOOL            │
└───────────────────────────────────────────┘
  1. Show System Info & RAM
  2. Check Disk Space
  3. Update Fedora Packages (dnf upgrade)
  4. Clean DNF Package Cache
  0. Exit
"""
        )

        choice = input("Select an option [0-4]: ").strip()

        if choice == "1":
            show_system_info()
        elif choice == "2":
            check_disk_space()
        elif choice == "3":
            update_fedora()
        elif choice == "4":
            clean_dnf_cache()
        elif choice == "0":
            clear_screen()
            print("Goodbye!")
            sys.exit(0)
        else:
            print("Invalid option, try again.")
            time.sleep(1)


if __name__ == "__main__":
    main()