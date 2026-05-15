# The problem has a variety of params related to the calculation. 
# it's generally a bad idea to just hard-code these directly. Better
# to assign to names. There is a secondary issue if where do these 
# names llive? Global vars, classes, func param?!

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