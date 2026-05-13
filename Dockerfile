# Dockerfile - C++ competitive programming dev environment for Programacao_Competitiva
# Usage:
# 1) Build: docker build -t cp-dev -f Programacao_Competitiva/Dockerfile .
# 2) Run (mount repo at /workspace):
#    docker run --rm -it -v "$(pwd)/Programacao_Competitiva:/workspace" cp-dev
# 3) Inside container:
#    g++ -std=gnu++20 -O2 -pipe -Wall -Wextra -o main Program.cpp && ./main

FROM ubuntu:22.04

# Configure noninteractive APT and timezone
ARG DEBIAN_FRONTEND=noninteractive
ARG TZ=UTC
ENV DEBIAN_FRONTEND=${DEBIAN_FRONTEND}
ENV TZ=${TZ}

# Create a non-root user that matches your host UID/GID to avoid permission issues
ARG UID=1000
ARG GID=1000
ARG USER=dev
ARG WORKSPACE=/workspace

# Base packages for C++ development and debugging
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    gdb \
    cmake \
    ninja-build \
    clang \
    clang-tidy \
    clang-format \
    lldb \
    git \
    curl \
    wget \
    ca-certificates \
    pkg-config \
    make \
    python3 \
    python3-pip \
    unzip \
    zip \
    time \
    tzdata \
    locales \
    sudo && \
    rm -rf /var/lib/apt/lists/*

# Set UTF-8 locale
RUN locale-gen en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Create user and workspace
RUN groupadd --gid ${GID} ${USER} && \
    useradd --uid ${UID} --gid ${GID} --create-home --shell /bin/bash ${USER} && \
    echo "${USER} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${USER} && \
    chmod 0440 /etc/sudoers.d/${USER} && \
    mkdir -p ${WORKSPACE} && \
    chown -R ${UID}:${GID} ${WORKSPACE}

WORKDIR ${WORKSPACE}
USER ${USER}

# Sensible defaults for competitive programming
ENV CC=gcc
ENV CXX=g++
ENV CPPFLAGS="-DLOCAL_DEBUG"
ENV CXXFLAGS="-std=gnu++20 -O2 -pipe -Wall -Wextra -Wshadow -Wconversion -fno-omit-frame-pointer"
ENV LDFLAGS="-Wl,-O1"

# Convenience: show compilers and versions on container start
RUN bash -lc 'echo "C++ toolchain:" && g++ --version | head -n1 && clang++ --version | head -n1 && cmake --version | head -n1'

# Default shell
CMD ["bash"]
