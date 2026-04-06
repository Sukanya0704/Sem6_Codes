import time

class EmployeeExpertSystem:
    def __init__(self):
        self.rules = [
            {
                "if_all": ["high_tech", "high_reliability", "high_soft"], 
                "conclusion": "EXECUTIVE MATERIAL (L5)", 
                "action": "Immediate promotion to Lead/Architect role."
            },
            {
                "if_all": ["high_tech", "low_soft"], 
                "conclusion": "TECHNICAL SPECIALIST", 
                "action": "Focus on leadership and communication workshops."
            },
            {
                "if_all": ["high_soft", "low_tech"], 
                "conclusion": "TEAM CATALYST", 
                "action": "Enroll in technical upskilling/bootcamps."
            },
            {
                "if_all": ["low_reliability"], 
                "conclusion": "CRITICAL RISK", 
                "action": "Immediate performance review and PIP."
            },
            {
                "if_all": ["high_reliability", "high_tech"], 
                "conclusion": "CORE SENIOR DEVELOPER", 
                "action": "Retain with high increment and technical autonomy."
            }
        ]
        self.facts = {}

    def ask(self, question):
        return input(f"{question} (y/n): ").lower() == 'y'

    def gather_facts(self):
        print("="*65)
        print("   EXPERT SYSTEM: KNOWLEDGE ACQUISITION PHASE (15 QUESTIONS)   ")
        print("="*65)
        name = input("Employee Name: ")

        t_score = sum([
            self.ask("1. Writes clean, optimized code?"),
            self.ask("2. Successfully handles complex debugging?"),
            self.ask("3. Mentors others on technical architecture?"),
            self.ask("4. Stays updated with latest AI/Cloud trends?")
        ])
        
        r_score = sum([
            self.ask("5. Consistently meets sprint deadlines?"),
            self.ask("6. Requires minimal follow-up from managers?"),
            self.ask("7. Follows documentation and coding standards?"),
            self.ask("8. Maintains high punctuality and availability?")
        ])

        s_score = sum([
            self.ask("9. Communicates effectively in meetings?"),
            self.ask("10. Handles critical feedback professionally?"),
            self.ask("11. Actively helps teammates during blockers?"),
            self.ask("12. Demonstrates high emotional intelligence?")
        ])

        i_score = sum([
            self.ask("13. Suggests process or tool improvements?"),
            self.ask("14. Takes ownership of unassigned tasks?"),
            self.ask("15. Demonstrates a 'product-first' mindset?")
        ])

        self.facts["high_tech"] = t_score >= 3
        self.facts["low_tech"] = t_score <= 1
        self.facts["high_reliability"] = r_score >= 3
        self.facts["low_reliability"] = r_score <= 1
        self.facts["high_soft"] = s_score >= 3
        self.facts["low_soft"] = s_score <= 1
        
        return name

    def inference_engine(self):
        print("\n[Inference Engine]: Matching Working Memory against Knowledge Base...")
        time.sleep(1.5)
        
        for rule in self.rules:
            match = all(self.facts.get(cond, False) for cond in rule["if_all"])
            
            if match:
                return rule 
        
        return {
            "conclusion": "STANDARD PERFORMER",
            "action": "Continue regular growth and quarterly reviews."
        }

    def run(self):
        name = self.get_user_input_name = self.gather_facts()
        result = self.inference_engine()
        
        print("\n" + "="*65)
        print(f" FINAL PERFORMANCE DIAGNOSIS: {name.upper()} ")
        print("="*65)
        print(f"CONCLUSION : {result['conclusion']}")
        print(f"ACTION     : {result['action']}")
        print("="*65)

if __name__ == "__main__":
    EmployeeExpertSystem().run()
