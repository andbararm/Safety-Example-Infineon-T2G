# Prepare a self-hosted runner

These installation instructions are written for a Raspberry Pi (mode 3/4/5) running an Arm64 Ubuntu server edition. For
other Linux OS, please adapt the steps.

## Prerequisites

The following commands need to be run to have all the required software installed on the local machine.

```sh
# Make sure your system is up-to-date
sudo apt update
sudo apt upgrade

# Install required tools
sudo apt install net-tools zip unzip
```

## Install pyOCD

```sh
# Download the latest self-contained binary
curl -o pyocd-linux-arm64-0.39.0.zip -L https://github.com/pyocd/pyOCD/releases/download/v0.39.0/pyocd-linux-arm64-0.39.0.zip

# Create a bin-directory in .local (is already in the path)
mkdir ~/.local/bin

# Extract pyOCD to that .local/bin directory
unzip ./pyocd-linux-arm64-0.39.0.zip ~/.local/bin

# Download udev rules for CMSIS-DAP adapters
curl -o 50-cmsis-dap.rules -L https://raw.githubusercontent.com/pyocd/pyOCD/refs/heads/main/udev/50-cmsis-dap.rules

# Copy udev rules to correct location
sudo cp *.rules /etc/udev/rules.d

# Force the udev system to reload
sudo udevadm control --reload
sudo udevadm trigger
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
