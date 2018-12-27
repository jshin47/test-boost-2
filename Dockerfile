# Get the base Ubuntu image from Docker Hub
FROM ubuntu:latest

# Update apps on the base image
RUN apt-get -y update && apt-get install -y

# Install the Clang compiler
RUN apt-get -y install clang cmake libboost-all-dev aptitude python3.6

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/boosted-baloo

# Specify the working directory 
WORKDIR /usr/src/boosted-baloo

# Run build
RUN bash build.sh || true

# Run the output program from the previous step
CMD ["python", "/usr/src/boosted-baloo/build/src/baloo/BalooModule.test.py"]