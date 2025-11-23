# Use Ubuntu 22.04 as the base Linux environment
FROM ubuntu:22.04

# Install the C++ compiler (g++) and make tools
RUN apt-get update && apt-get install -y build-essential

# Set the working directory inside the container
WORKDIR /app

# Default command: open a bash terminal
CMD ["bash"]