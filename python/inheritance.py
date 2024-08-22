# Copyright 2024 Adam-Al-Rahman
# yt: https://www.youtube.com/watch?v=X1PQ7zzltz4

# Dummy Server Database
server = {
    "database": {
        "havoc#coder": {
            "email": "havoc@gmail.com",
            "password": "#Havoc#@77",
            "lastLogin": "24-12-2024#21:44:26",
            "played": {
                "25-12-2024#00:44:26": {
                    "agent": "KillJoy",
                    "score": "-12",
                },
                "24-12-2024#23:58:32": {
                    "agent": "KillJoy",
                    "score": "+17",
                },
            },
        },
        "Adam#coder": {
            "password": "#Code#@0111",
            "lastLogin": "24-12-2024#22:58:33",
            "played": {
                "25-12-2024#23:58:32": {
                    "agent": "Omen",
                    "score": "-5",
                },
                "24-12-2024#00:44:26": {
                    "agent": "Viper",
                    "score": "+34",
                },
            },
        },
    }
}


class User:
    """Represents a user with an ID, log status, and password status."""

    default_status = "Logged Out"

    def __init__(self, user_id: str, email: str):
        """Initializes a User with the given ID."""
        self.log_status = User.default_status
        self.user_id = user_id
        self.email = email
        self.password_status = "invalid"

    def sign_in(self, password: str):
        """Signs in the user if the password matches the one in the server."""
        user_data = server["database"].get(self.user_id)
        if user_data:
            if self.email == user_data["email"] and password == user_data["password"]:
                self.log_status = "Logged In"
                self.password_status = "valid"
            else:
                print(f"Password status: {self.password_status}")
        else:
            print(f"User {self.user_id} does not exist.")

    def get_status(self):
        """Returns the log status of the user."""
        return self.log_status


class Agent(User):
    """Represents an agent, inheriting from User."""

    def __init__(self, user_id: str, email: str):
        """Initializes an Agent with the given user ID."""
        super().__init__(user_id, email)

    def attack(self):
        """Defines the attack behavior for the agent."""
        pass

    def get_status(self):
        """Returns the log status of the agent, using the superclass method."""
        status = super().get_status()
        return f"Agent status: {status}"


class KillJoy(Agent):
    """Represents the KillJoy agent."""

    def __init__(self, user_id: str, email: str):
        """Initializes a KillJoy agent with the given user ID."""
        super().__init__(user_id, email)
        self.agent = "KillJoy"
        self.abilities = {
            "signature": "Turret",
            "ability_c": "Nanoswarm",
            "ability_q": "AlarmBot",
            "ultimate": "lockdowm",
        }
        self.quotes = [
            "Don't interrupt my work.",
            """
            I built literally everything on this battlefield.
            Ja, even the things that might kill us.
            What? You want me to say sorry?
            """,
            """
            Astra, after this let's grab coffee and talk theoretical physics.
            Just us girls, ja?
            """,
            """
            Viper, do you mind if I run today's tests.
            You're a little too biased, no offense.
            """,
            """
            There's a Viper over there.
            What a shame to rid the world of that mind.
            But I think she needs to rest.
            """,
            "I'll get that spooky ghost boy!",
            "Imagine if I died, right now. So funny...",
        ]

    # dundar method __x__
    def __call__(self):
        import random

        return random.choice(self.quotes)

    def __getitem__(self, index):
        return self.abilities[index]


class Viper(Agent):
    """Represents the Viper agent."""

    def __init__(self, user_id: str, email: str):
        """Initializes a Viper agent with the given user ID."""
        super().__init__(user_id, email)
        self.special_ability = "Snake Bite"


class Omen(Agent):
    """Represents the Omen agent."""

    def __init__(self, user_id: str, email: str):
        """Initializes an Omen agent with the given user ID."""
        super().__init__(user_id, email)
        self.special_ability = "Shrouded Step"


def main():
    """Main function to demonstrate the use of the classes."""
    havoc = KillJoy("havoc#coder", "havoc@gmail.com")
    print(havoc.get_status())  # Output: Agent status: Logged Out

    havoc.sign_in("#Havoc#@77")
    print(havoc.get_status())  # Output: Agent status: Logged In

    # use modified __call__
    print(havoc())

    # use modified __getitem__
    print(f"{havoc.agent} signature ability: {havoc['signature']}")

    print(f"Is `havoc` Instance of User: {isinstance(havoc, User)}")
    print(f"Is `havoc` Instance of Agent: {isinstance(havoc, Agent)}")
    print(f"Is `havoc` Instance of KillJoy: {isinstance(havoc, KillJoy)}")


if __name__ == "__main__":
    main()
