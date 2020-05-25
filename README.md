# Intro
`limited` is a tool to launch a command with limited access to ressources. For now, `limited` can only limit the amount of physical memory. But in theory, `limited` can limit everything that `cgroup policy` can limit.

# Prerequisites
Before using `limited`, you have to enable cgroups on your system.

For Ubuntu, do the following steps:
* `sudo apt-get install cgroup-tools`
* Add `cgroup_enable=memory swapaccount=1` to `GRUB_CMDLINE_LINUX_DEFAULT` in `/etc/default/grub`
* `sudo update-grub`

For others distros, good luck !

# Usage
`limited [-m amount] cmd`

Exemple:
* `limited -m 500M ./my_very_greedy_binary`
* `limited -m 10G ls -alh`

# Outro
I would really like to have others limitations. Feel free to PR :)