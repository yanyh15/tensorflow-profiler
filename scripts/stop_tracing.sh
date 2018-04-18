#!/bin/bash

usage()
{
    echo "Usage: $0 [-k | --kernel]
            where:
                -k | --kernel : stop kernel lttng session" 1>&2; exit 1; }

is_sudo=" "

while true; do
    case "$1" in
        -k | --kernel ) is_sudo=sudo; shift;;
        -h | --help ) usage; shift;;
        -- ) shift; break ;;
        * ) break ;;
    esac
done

$is_sudo lttng destroy

if [ "$is_sudo" == "sudo" ];
then
    echo "sudo chown -R `whoami` ../lttng-traces"
    sudo chown -R `whoami` ../lttng-traces
fi