package main

import (
	"net/http"
	"time"
)

// A buffered channel that we can send work requests on.
var WorkQueue = make(chan WorkRequest, 100)

func Collector(w http.ResponseWriter, r *http.Request) {
	if r.Method != "POST" {
		w.Header().Set("ALLOW", "POST")
		w.WriteHeader(http.StatusBadRequest)
		return
	}

	// parse the delay
	delay, err := time.ParseDuration(r.FormValue("delay"))
	if err != nil {
		http.Error(w, "The delay must be between 1 and 10 seconds, inclusively.", http.StatusBadRequest)
		return
	}
}
