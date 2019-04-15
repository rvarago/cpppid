FROM conanio/gcc8:1.14.1

USER root

WORKDIR cpppid

COPY . .

CMD ["/bin/bash"]
