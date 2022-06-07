build: go15 go16 go17 go18

go15:
	rm -f go.mod
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.15 go mod init bpf.plus/talk0/golang
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.15 go build -o hello15

go16:
	rm -f go.mod
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.16 go mod init bpf.plus/talk0/golang
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.16 go build -o hello16

go17:
	rm -f go.mod
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.17 go mod init bpf.plus/talk0/golang
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.17 go build -o hello17

go18:
	rm -f go.mod
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.18 go mod init bpf.plus/talk0/golang
	docker run -it --rm -v ${PWD}:/home/src -w /home/src golang:1.18 go build -o hello18

run:
	./hello15 hello world
	./hello16 hello world
	./hello17 hello world
	./hello18 hello world

right:
	./right.bt

wrong:
	./wrong.bt

clean:
	rm -f ./hello15
	rm -f ./hello16
	rm -f ./hello17
	rm -f ./hello18
	rm -f go.mod
