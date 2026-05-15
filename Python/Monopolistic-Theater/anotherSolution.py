BASE_PRICE = 5.0                        # Dollars
ATTENDEES_PER_DOLLAR = 150              # 150 people per dollar (15 people per 10 cents)
BASE_ATTENDEES = 120                    # Numbers of attendees at base price
FIXED_COST = 180.0                      # Dollars
COST_PER_ATTENDEE = 0.04                # Dollars

def compute_attendees(price):
    return BASE_ATTENDEES - (price - BASE_PRICE)*ATTENDEES_PER_DOLLAR

def compute_cost(attendees):
    return FIXED_COST + COST_PER_ATTENDEE*attendees

def compute_profit(price):
    num_attendees = compute_attendees(price)
    revenue = num_attendees*price
    cost = compute_cost(num_attendees)
    return revenue - cost

# Loop search params:

LOW_PRICE = 1.0
HIGH_PRICE = 9.0
INCREMENT = 0.10

def find_ticket_price():
    price = LOW_PRICE
    best_price = price 
    best_profit = compute_profit(price)
    while price < HIGH_PRICE:
        price += INCREMENT
        profit = compute_profit(price)
        if profit >= best_profit:
            best_price = price
            best_profit = profit
    return best_price

print(find_ticket_price())