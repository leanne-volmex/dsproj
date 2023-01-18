FROM archlinux

RUN pacman -Syu --noconfirm
RUN pacman -S --noconfirm cmake g++

COPY . /app
WORKDIR /app

RUN cmake .
RUN make

CMD ["./dsproj"]