package main

import "fmt"

type User struct {
	ID       int
	Username string
}

type Server struct {
	db map[int]*User
}

func NewServer() *Server {
	db := make(map[int]*User)

	for i := 0; i < 100; i++ {
		db[i+1] = &User{
			ID:       i + 1,
			Username: fmt.Sprintf("user_%d", i+1),
		}
	}

	return &Server{
		db: db,
	}
}

func main() {

}
