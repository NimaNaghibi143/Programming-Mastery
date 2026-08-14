package main

import "time"

func main() {

}

func fetchThirdPartyStuffWhichCanBeSlow() (int, error) {
	time.Sleep(time.Microsecond * 500)

	return 666, nil
}
