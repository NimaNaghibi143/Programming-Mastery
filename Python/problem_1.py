# theater.py
#
# The owner of a monopolistic movie theater in a small town has
# complete freedom in setting ticket prices.  The more he charges, the
# fewer people can afford tickets.  The less he charges, the more it
# costs to run a show because attendance goes up.  In a recent
# experiment the owner determined a relationship between the price of
# a ticket and average attendance.
#
# At a price of $5.00/ticket, 120 people attend a performance.  For
# each 10-cent change in the ticket price, the average attendance
# changes by 15 people.  That is, if the owner charges $5.10, some 105
# people attend on the average; if the price goes down to $4.90,
# average attendance increases to 135.
#
# Unfortunately, the increased attendance also comes at an increased
# cost.  Every performance comes at a fixed cost of $180 to the owner
# plus a variable cost of $0.04 per attendee.
#
# The owner would like to know the exact relationship between profit
# and ticket price in order to maximize the profit.
#
# Write a program to figure out the best ticket price (to the nearest
# 10 cents) that maximizes profit.

# The problem has a variety of params related to the calculation. 
# it's generally a bad idea to just hard-code these directly. Better
# to assign to names. There is a secondary issue if where do these 
# names llive ? Global vars, classes, func param?!

BASE_PRICE = 5.0                        # Dollars
ATTENDEES_PER_DOLLAR = 150              # 150 people per dollar (15 people per 10 cents)
BASE_ATTENDEES = 120                    # Numbers of attendees at base price
FIXED_COST = 180.0                      # Dollars
COST_PER_ATTENDEE = 0.04                # Dollars

def compute_attendees(TP):
    return int(BASE_ATTENDEES + (BASE_PRICE-TP)*ATTENDEES_PER_DOLLAR)

def compute_revenue(TP):
    return float(TP*compute_attendees(TP))

def compute_cost(TP):
    return float(FIXED_COST + COST_PER_ATTENDEE*compute_attendees(TP))

def compute_profit(TP):
    return float(compute_revenue(TP) - compute_cost(TP))

def optimize(LB, UB):
    profit = []
    # The fact that "range" does not accept floats as steps is painful,
    # while numpy "arrange" does so with ease...
    for TP in range(LB*10, UB*10):
        TP = TP/10
        profit.append((TP, compute_profit(TP)))
    profit.sort(key=lambda x: x[1], reverse=True)
    best_TP, best_profit = profit[0]
    return print(f"Best Ticket Price is {best_TP} with a corresponding value of ${best_profit} in Profit.")

optimize(0, 100)