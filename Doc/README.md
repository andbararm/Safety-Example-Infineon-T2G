# Self-Hosted Runner for Execution Test

The CMSIS-Toolbox implements and [Run and Debug Configuration](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview/#run-and-debug-configuration) for command line usage with pyOCD. pyOCD is a debug connector used in [Keil Studio] that offers also command-line operation for Continuous Integration (CI).

This section explains how to setup a Linux box that runs a GitHub self-hosted runner for programming and execution of an application. The [build workflow](../.github/workflows/Build_T2G_Release.yaml) is executed on a GitHub hosted runner that stores the build output as an artifact.

![CI and HiL Test](CI_HIL.png "CI and HiL Test")

## Prepare a self-hosted runner

These installation instructions are written for a Raspberry Pi (mode 3/4/5) running an Arm64 Ubuntu server edition.
They have been tested on [Ubuntu Server 24.0.3 LTS](https://ubuntu.com/download/server). For other Linux OS, please
adapt the steps.

## Prerequisites

The following commands need to be run to have all the required software installed on the local machine.

```sh
# Make sure your system is up-to-date
sudo apt update && sudo apt upgrade

# Install required tools
sudo apt install net-tools zip unzip
```

### Install pyOCD

> [!NOTE]
> Ubuntu Server 24.0.3 already comes with Python 3.12.x which is used in the following to describe the set up of
> `pyocd` in a virtual environment. Please make sure to install an appropriate Python version on your system as well.

```sh
# Create a virtual environment
python -m venv ~/pyocd_venv

# Activate the virtual environment
source ~/pyocd_venv/bin/activate

# Install pyocd
pip3 install pyocd
```

## Install the self-hosted runner

### Download and extract the runner

In GitHub → repo or org → Settings → Actions → Runners → New self-hosted runner → Linux → ARM/ARM64. You’ll see a
download link and a registration token. On the Pi:

```sh
mkdir ~/actions-runner && cd ~/actions-runner
curl -o actions-runner-linux-arm64.tar.gz -L https://github.com/actions/runner/releases/download/vX.Y.Z/actions-runner-linux-arm64-X.Y.Z.tar.gz
tar xzf ./actions-runner-linux-arm64.tar.gz
```

#### Install dependencies

```sh
sudo ./bin/installdependencies.sh
```

### Configure the runner

```sh
./config.sh \
  --url https://github.com/<OWNER>/<REPO_OR_ORG> \
  --token <TOKEN> \
  --name rpi
```

### Run persistently

```sh
sudo ./svc.sh install
sudo ./svc.sh start
sudo ./svc.sh status
```
