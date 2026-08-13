# The Problem

Create a library for caching user information to increase database throughput and availability. every request for the user data should return the user information while simultaneously taking care of the data base throughput. it means the library should take care of unnecessary requests for user data if some are pending.

WHY: 

Let's say we have a bunch of user information (identified by id) inside our main database. 
Simultaneously there is thousands of requests per second for user inforamation.
we can consider that database is a bottleneck right. to avoid that we need a cache mechanism.

NOTES:

You can use any language, library, database and framework - anything you want and think is for this case.

Example:

If within 1000 requests there are 100 unique user ids then there should be only a maximum 100 requests into the database 
but all 1000 requests should get a response with a user data.