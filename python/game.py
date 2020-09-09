import sys
import time
import random as rd

def menu(sword_attack,max_hp,current_hp,level,exp,playing_time,money):
    print("MENU")
    playing_time_minutes=(time.time()-playing_time)/60
    print("You are playing",int(playing_time_minutes),"min")
    print("""Your stats:""",'\n',"""Sword attack -""",sword_attack,'\n',
          """Max hp -""", max_hp, '\n',
          """Current hp-""", current_hp,'\n',
          """Current money- """,money,'\n',
          """Your level -""", level,'\n',
          """Experience you need to next level - """,level*50-exp)

    while True:
        what_do = input("""Write what do you want to do:
                    start (start game)
                    restart (restart your progress)
                    exit (exit from game)""")
        if what_do == "start":
            game(sword_attack,max_hp,current_hp,level,exp,money)
        elif what_do == "restart":
            while True:
                sure = input("Are you sure? (print 'yes' or 'no') ")
                if sure == "yes":
                    sword_attack = 1
                    hp = 10
                    level = 1
                    exp = 0
                    menu(sword_attack,hp,level,exp,playing_time,money)
                elif sure == "no":
                    menu(sword_attack, hp, level, exp, playing_time,money)
        elif what_do == "exit":
            while True:
                will_save = input("Do you want save progress? (write 'yes or 'no' or 'back' if you want back to menu')")
                if will_save == "yes":
                    print("soon")
                elif will_save == "no":
                    print("Thanks for playing")
                    sys.exit()
                elif will_save == "back":
                    menu(sword_attack,max_hp,current_hp,level,exp,playing_time,money)
        else:
            print("We don`t have option", what_do)



def game(sword_attack,max_hp,current_hp,level,exp,money):
    monsters = ["wolf", "goblin", "skeleton", "barbarian", "bat", "archer", "musketeer", "viking", "lizard", "knight"]
    while True:

        small_heal_potion_from_fight = level
        normal_heal_potion_from_fight = 1 + level
        big_heal_potion_from_fight = 2 + level

        wolf_hp = 2
        wolf_dmg = 2
        wolf_exp = 25
        wolf_reward = 10

        goblin_hp = 3
        goblin_dmg = 3
        goblin_exp = 40
        goblin_reward = 15

        skeleton_hp = 2
        skeleton_dmg = 4
        skeleton_exp = 50
        skeleton_reward = 17

        barbarian_hp = 5
        barbarian_dmg = 4
        barbarian_exp = 80
        barbarian_reward = 35

        bat_hp = 3
        bat_dmg = 6
        bat_exp = 85
        bat_reward = 37

        archer_hp = 3
        archer_dmg = 4
        archer_exp = 100
        archer_reward = 50

        musketeer_hp = 4
        musketeer_dmg = 6
        musketeer_exp = 150
        musketeer_reward = 65

        viking_hp = 12
        viking_dmg = 10
        viking_exp = 175
        viking_reward = 75

        lizard_hp = 8
        lizard_dmg = 15
        lizard_exp = 190
        lizard_reward = 80

        knight_hp = 15
        knight_dmg = 12
        knight_exp = 205
        knight_reward = 100

        print("""Your stats:""", '\n', """Sword attack -""", sword_attack, '\n',
              """Max hp -""", max_hp, '\n',
              """Current hp-""", current_hp, '\n',
              """Current money- """, money, '\n',
              """Your level -""", level, '\n',
              """Experience you need to next level - """, level * 50 - exp)

        while True:
            one_more = input("Do you want beat one more monster? Write 'yes' to beat one more monster, 'shop' to go to the shop or 'menu' to open menu ")
            if one_more == "yes":
                break
            elif one_more == "shop":
                shop(money,level,max_hp,current_hp,sword_attack)
            elif one_more == "menu":
                menu(sword_attack, max_hp, current_hp, level, exp, playing_time,money)


        max_monster = level
        if max_monster > len(monsters)-1:
            max_monster=len(monsters)-1

        monster = monsters[rd.randrange(0, max_monster, 1)]
        print("You fight with",monster)
        while monster == "wolf":
            wolf_hp = wolf_hp - sword_attack
            if wolf_hp <= 0:
                exp = exp + wolf_exp
                money = money + wolf_reward
                print("You WON!")
                if exp >= level*50:
                    exp = exp - level*50
                    level = level + 1
                    max_hp = max_hp + 1
                break
            current_hp = current_hp - wolf_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break

        while monster == "goblin":
            goblin_hp = goblin_hp - sword_attack
            if goblin_hp <= 0:
                exp = exp + goblin_exp
                money = money + goblin_reward
                print("You WON!")
                if exp >= level*50:
                    exp = exp - level*50
                    level = level + 1
                    max_hp = max_hp +1
                break
            current_hp = current_hp - goblin_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break

        while monster == "skeleton":
            skeleton_hp = skeleton_hp - sword_attack
            if skeleton_hp <= 0:
                exp = exp + skeleton_exp
                money = money + skeleton_reward
                print("You WON!")
                if exp >= level*50:
                    exp = exp - level*50
                    level = level + 1
                    max_hp = max_hp + 1
                break
            current_hp = current_hp - skeleton_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break

        while monster == "barbarian":
            barbarian_hp = barbarian_hp - sword_attack
            if barbarian_hp <= 0:
                exp = exp + barbarian_exp
                money = money + barbarian_reward
                print("You WON!")
                if exp >= level * 50:
                    exp = exp - level * 50
                    level = level + 1
                    max_hp = max_hp + 1
                break
            current_hp = current_hp - barbarian_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break

        while monster == "bat":
            bat_hp = bat_hp - sword_attack
            if bat_hp <= 0:
                exp = exp + bat_exp
                money = money + bat_reward
                print("You WON!")
                if exp >= level * 50:
                    exp = exp - level * 50
                    level = level + 1
                    max_hp = max_hp + 1
                break
            current_hp = current_hp - bat_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break

        while monster == "archer":
            current_hp = current_hp - archer_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break
            archer_hp = archer_hp - sword_attack
            if archer_hp <= 0:
                exp = exp + archer_exp
                money = money + archer_reward
                print("You WON!")
                if exp >= level * 50:
                    exp = exp - level * 50
                    level = level + 1
                    max_hp = max_hp + 1
                break

        while monster == "musketeer":
            current_hp = current_hp - musketeer_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break
            musketeer_hp = musketeer_hp - sword_attack
            if musketeer_hp <= 0:
                exp = exp + musketeer_exp
                money = money + musketeer_reward
                print("You WON!")
                if exp >= level * 50:
                    exp = exp - level * 50
                    level = level + 1
                    max_hp = max_hp + 1
                break

        while monster == "viking":
            viking_hp = viking_hp - sword_attack
            if viking_hp <= 0:
                exp = exp + viking_exp
                money = money + viking_reward
                print("You WON!")
                if exp >= level * 50:
                    exp = exp - level * 50
                    level = level + 1
                    max_hp = max_hp + 1
                break
            current_hp = current_hp - viking_dmg
            if current_hp <= 0:
                print("You lost")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
                break

            while monster == "lizard":
                lizard_hp = lizard_hp - sword_attack
                if lizard_hp <= 0:
                    exp = exp + lizard_exp
                    money = money + lizard_reward
                    print("You WON!")
                    if exp >= level * 50:
                        exp = exp - level * 50
                        level = level + 1
                        max_hp = max_hp + 1
                    break
                current_hp = current_hp - lizard_dmg
                if current_hp <= 0:
                    print("You lost")
                    current_hp = max_hp
                    if sword_attack > 1:
                        sword_attack = sword_attack - 1
                    if max_hp > 10:
                        max_hp = max_hp - 1
                        exp = exp / 2
                    break

            while monster == "knight":
                knight_hp = knight_hp - sword_attack
                if knight_hp <= 0:
                    exp = exp + knight_exp
                    money = money + knight_reward
                    print("You WON!")
                    if exp >= level * 50:
                        exp = exp - level * 50
                        level = level + 1
                        max_hp = max_hp + 1
                    break
                current_hp = current_hp - knight_dmg
                if current_hp <= 0:
                    print("You lost")
                    current_hp = max_hp
                    if sword_attack > 1:
                        sword_attack = sword_attack - 1
                    if max_hp > 10:
                        max_hp = max_hp - 1
                        exp = exp / 2
                    break


        event = rd.randrange(0,100)
        if event <= 10:
            print("You won 100 money!")
            money = money + 100
        elif event > 10 and event <= 20:
            print("Trap! You lost",level,"hp!")
            current_hp = current_hp - level
            if current_hp <= 0:
                print("You lose")
                current_hp = max_hp
                if sword_attack > 1:
                    sword_attack = sword_attack - 1
                if max_hp > 10:
                    max_hp = max_hp - 1
                    exp = exp / 2
        elif event > 20 and event <= 40:
            print("You get small heal potion!")
            current_hp = current_hp + small_heal_potion_from_fight
            if current_hp > max_hp:
                current_hp = max_hp
        elif event > 40 and event < 50:
            print("You get normal heal potion!")
            current_hp = current_hp + normal_heal_potion_from_fight
            if current_hp > max_hp:
                current_hp = max_hp
        elif event == 50:
            mega_prize = rd.randrange(1,5,1)
            print("You won MEGA prize!")
            print("drawing")
            time.sleep(1)
            print("3")
            time.sleep(1)
            print("2")
            time.sleep(1)
            print(1)
            time.sleep(1)
            if mega_prize == 1:
                money = money + level*200
                print("You won",level*200, "money!")
            elif mega_prize == 2:
                sword_attack = sword_attack + 4
                print("Your sword power has increased by 4!")
            elif mega_prize == 3:
                max_hp = max_hp + 4
                print("Your max hp has increased by 6!")
            elif mega_prize == 4:
                level = level + 2
                max_hp = max_hp + 2
                print("You got 2 levels!")
            elif mega_prize == 5:
                sword_attack = sword_attack + 2
                max_hp = max_hp + 2
                money = money + level*50
                print("Your max hp and sword atack has increased by 2 and you got",level*50,"money!")
        elif event > 50 and event <= 60:
            print("Your sword power has been increased by 1!")
            sword_attack = sword_attack +1
        elif event > 60 and event <= 70:
            print("You found big heal potion!")
            current_hp = current_hp + big_heal_potion_from_fight
            if current_hp > max_hp:
                current_hp = max_hp
        elif event > 70 and event <= 90:
            print("You found empty box")
        elif event > 90 and event <= 100:
            print("You lost",level*5,"money")
            if money - level*5 < 0:
                money = 0
            else:
                money = money - level*5





def shop(money,level,max_hp, current_hp,sword_attack):
    max_heal_potion_cost = level*2 + 40

    upgrade_max_hp_for_1 = 1
    upgrade_max_hp_for_1_cost = level*3 + 20

    sword_upgrade = 1
    sword_upgrade_cost = 60 + level*2


    while True:
        max_heal_potion = max_hp

        print("You have", money, ("money"))
        print("""Write what do you want to buy (number)""",'\n' , """1 = max heal potion. You get max hp - cost: """,max_heal_potion_cost,'\n'
            """2 = improve your max hp by 1 - cost: """,upgrade_max_hp_for_1_cost, '\n',
            """3 = improve your sword power by 1 - cost: """,sword_upgrade_cost)
        what_buy = input("If you want return to game write 0 ")
        if what_buy == "0":
            game(sword_attack, max_hp, current_hp, level, exp, money)
        elif what_buy == "1":
            if max_heal_potion_cost > money:
                print("You don`t have enough money")
            else:
                current_hp = max_heal_potion
                money = money - (max_heal_potion_cost)
        elif what_buy == "2":
            if upgrade_max_hp_for_1_cost > money:
                print("You don`t have enough money")
            else:
                max_hp = max_hp + upgrade_max_hp_for_1
                money = money - (upgrade_max_hp_for_1_cost)
        elif what_buy == "3":
            if sword_upgrade_cost > money:
                print("You don`t have enough money")
            else:
                sword_attack = sword_attack + sword_upgrade
                money = money - (sword_upgrade_cost)


if __name__ == '__main__':
    playing_time=time.time()
    sword_attack=1
    max_hp=10
    current_hp=10
    level=1
    exp=0
    money=0
    print("Welcome to my console game :) MADE BY DOG")
    menu(sword_attack,max_hp,current_hp,level,exp,playing_time,money)
