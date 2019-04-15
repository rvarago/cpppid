FROM conanio/gcc8:1.14.1

USER root

RUN sudo apt-get update -qq \
	&& apt-get install -y --no-install-recommends qemu-user

WORKDIR cpppid

COPY . .

CMD ["/bin/bash"]
