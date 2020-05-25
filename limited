#!/usr/bin/env python3
import os
import sys
import subprocess
import uuid
from optparse import OptionParser

def prepare_group(options):
    # Generate unique name for group.
    group_name = str(uuid.uuid4())

    # Create the group.
    os.system("sudo cgcreate -t $USER:$USER -a $USER:$USER -g memory:" + group_name)

    # Set memory limit.
    memory_cli = options.memory
    if memory_cli:
        # Parse unit.
        unit_cli = memory_cli[len(memory_cli)-1]
        multiplier = 1
        if unit_cli == 'K':
            multiplier = 1000
        elif unit_cli == 'M':
            multiplier = 1000*1000
        elif unit_cli == 'G':
            multiplier = 1000*1000*1000
        
        # Parse limit.
        limit = int(memory_cli[:len(memory_cli) - 1]) * multiplier
        os.system("echo " + str(limit) + " > /sys/fs/cgroup/memory/" + group_name + "/memory.limit_in_bytes")

    return group_name

def execute_command(group_name, args):
    cmd = " ".join(args[1:])
    os.system("cgexec -g memory:" + group_name + " " + cmd)

def delete_group(group_name):
    os.system("sudo cgdelete memory:" + group_name)

def main():
    # Parse CLI.
    parser = OptionParser()
    parser.add_option("-m", "--memory", action="store", type="string", dest="memory")
    (options, args) = parser.parse_args(sys.argv)

    # Prepare group.
    group_name = prepare_group(options)

    # Execute the command inside the group.
    execute_command(group_name, args)

    # Delete group.
    delete_group(group_name)

if __name__ == "__main__":
    main()