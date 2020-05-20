import sys
import math

# Grab Snaffles and try to throw them through the opponent's goal!
# Move towards a Snaffle to grab it and use your team id to determine towards where you need to throw it.
# Use the Wingardium spell to move things around at your leisure, the more magic you put it, the further they'll move.

my_team_id = int(input())  # if 0 you need to score on the right of the map, if 1 you need to score on the left

# define the goal
if my_team_id == 0:
    our_goal = (0, 3750)
    enemy_goal = (16000, 3750)
    our_wizard = (0, 1)
    enemy_wizard = (2, 3)
else:
    enemy_goal = (0, 3750)
    our_goal = (16000, 3750)
    our_wizard = (2, 3)
    enemy_wizard = (0, 1)

# function calculate distance between two entity
def distance(x1, y1, x2, y2):
    return math.sqrt(abs(float(x1) - float(x2))**2 + abs(float(y1) - float(y2))**2)
    
def inside(x1, y1, x2, y2, r):
    dis = distance(x1, y1, x2, y2)
    if dis > r:
        return False
    else:
        return True
        
"""
1. get entity
2. calcuate 4 snaffles
    - closest to enemy goal
    - closest to our goal
    - closest to our wizard
3. Make a function to choose to protect the goal or to attack
4. Make a function to calculate will it collide
    - calculate where to go
    - calculate will it collide soon
    
    1. check the distance
    2. check the bloger sight is it coming to me?
    3. if that so then calculate how much offset will give
    

"""

# 2
def calculate_snaffle(entity, snaffle_num):
    # Store the informations at one dictionary
    snaffle_info = {}
    
    snaffle_info['snaffle_num'] = snaffle_num
    # two wizard and snaffles
    for wizard_i in our_wizard:
        min_distance = 10000000
        for snaffle_i in snaffle_ids:
            # if one snaffle is targeted by other wizard ignore it
            if wizard_i == 1 or wizard_i == 3:
                if snaffle_num == 1:
                    snaffle_info['wizard_{}'.format(wizard_i)] = snaffle_i
                    break
                if snaffle_info['wizard_{}'.format(wizard_i - 1)] == snaffle_i:
                    continue
            # snaffle
            x1, y1 = entity[snaffle_i][1:3]
            
            # player
            x2, y2 = entity[wizard_i][1:3]
            
            snaffle_dis = distance(x1, y1, x2, y2)
            if snaffle_dis < min_distance:
                min_distance = snaffle_dis
                snaffle_info['wizard_{}'.format(wizard_i)] = snaffle_i 
                
    # check the closest one
    snaffle0 = entity[snaffle_info['wizard_{}'.format(our_wizard[0])]][1:3]
    snaffle1 = entity[snaffle_info['wizard_{}'.format(our_wizard[1])]][1:3]
    wizard_0 = entity[our_wizard[0]][1:3]
    wizard_1 = entity[our_wizard[1]][1:3]
        
    total_0_dis = distance(*snaffle0, *wizard_0) + distance(*snaffle1, *wizard_1)
    total_1_dis = distance(*snaffle0, *wizard_1) + distance(*snaffle1, *wizard_0)
    
    if total_1_dis < total_0_dis:
        snaffle_info['wizard_{}'.format(our_wizard[0])], snaffle_info['wizard_{}'.format(our_wizard[1])] =  snaffle_info['wizard_{}'.format(our_wizard[1])], snaffle_info['wizard_{}'.format(our_wizard[0])]
                
    # Closest snaffle from goal
    enemy_min_distance = 10000000
    our_min_distance = 10000000
    # goal
    for snaffle_i in snaffle_ids:
        # snaffle
        x1, y1 = entity[snaffle_i][1:3]
        
        enemy_goal_dis = distance(x1, y1, *enemy_goal)
        our_goal_dis = distance(x1, y1, *our_goal)
        
        if enemy_goal_dis < enemy_min_distance:
            enemy_min_distance = enemy_goal_dis
            snaffle_info['enemy_snaffle'] = snaffle_i
        if our_goal_dis < our_min_distance:
            our_min_distance = our_goal_dis
            snaffle_info['our_snaffle'] = snaffle_i
    
    return snaffle_info
    
def calculate_wizard_position(entity):
    x_0 = entity[our_wizard[0]][1]
    x_1 = entity[our_wizard[1]][1]
    goal_x = our_goal[0]
    
    dis_0 = abs(goal_x - x_0)
    dis_1 = abs(goal_x - x_1)
    if dis_0 >= dis_1:
        return {'attack': our_wizard[0], 'defense': our_wizard[1]}
    else:
        return {'attack': our_wizard[1], 'defense': our_wizard[0]}
        
def rotate(entity, wizard_i, x, y, bludger_ids):
        
    w_x, w_y, vx, vy = entity[wizard_i][1:5]
    r = distance(w_x, w_y, x, y)
    if r:
        w_vx, w_vy = ((x - w_x)/r)*500, ((y - w_y)/r)*500
    else:
        w_vx, w_vy = x - w_x, y - w_y
    
    b1_x, b1_y, b1_vx, b1_vy = entity[bludger_ids[0]][1:5]
    b2_x, b2_y, b2_vx, b2_vy = entity[bludger_ids[1]][1:5]
    
    # calculate will it collide?:
    w_r = distance(0, 0, w_vx, w_vy)
    if w_r == 0:
        w_theta = 0
    else:
        w_theta = math.acos(w_vx/w_r)
    
    best_sec = 0 
    best_theta = 0
    best_vx = 0
    best_vy = 0
    
    for theta in range(1, 22):
        offset = (math.pi/2)*(theta//2)*((-1)**theta)/10
        offset_theta = w_theta + offset
        offset_vx, offset_vy = math.cos(offset_theta)*w_r, math.sin(offset_theta)*w_r
        if w_vy < 0:
            offset_vy *= -1
        # print("offset : {} offset_vx: {} offset_vy : {}".format(offset, offset_vx, offset_vy), file=sys.stderr)
        real_vx = offset_vx + vx*1.
        real_vy = offset_vy + vy*1.
        # print("w_vx, w_vy, real vx vy", w_vx, w_vy, real_vx, real_vy, file=sys.stderr)
        collide_sec = [100, 100]
        for sec in range(1, 51):
            sec *= 0.2
            b1_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              b1_x + b1_vx * sec,
                              b1_y + b1_vy * sec)
            b2_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              b2_x + b2_vx * sec,
                              b2_y + b2_vy * sec)
            if collide_sec[0] == 100 and b1_dis < 800:
               collide_sec[0] = sec 
            if collide_sec[1] == 100 and b2_dis < 800:
               collide_sec[1] = sec 
            # print("rotate theta {}, collide {}".format(theta, collide_sec), file=sys.stderr)
               
        sec_result = min(collide_sec)
        
        # compare and update the info
        if sec_result > best_sec:
            best_sec = sec_result
            best_theta = offset_theta
            best_vx = offset_vx
            best_vy = offset_vy
            # print(best_theta, file=sys.stderr)
        if best_sec == 100:
            break
    
    x, y = w_x + (best_vx)*100, w_y + (best_vy)*100
    x, y = math.ceil(x), math.ceil(y)
               
    return x, y

def search(entity, wizard_i, snaffle_ids):
    w_x, w_y = entity[wizard_i][1:3]
    r = distance(w_x, w_y, *enemy_goal)
    
    # vector x and y
    # default vector is looking at the goal from selectd wizard
    v_x, v_y = ((enemy_goal[0] - w_x)/r)*100, ((enemy_goal[1] - w_y)/r)*100
    if r:
        theta = math.acos(v_x/r)
    else:
        theta = 0
    
    # 15 degree check
    for angle_i in range(1, 26):
        angle = math.pi*((angle_i//2)*((-1)**angle_i))/12
        for snaffle_i in snaffle_ids:
            pass
    
def move(entity, bludger_ids, wizard_i, snaffle, thrust=150):
    # estimate the snaffle final destination 
    x, y, vx, vy = snaffle[1:5]
    w_x, w_y = entity[wizard_i][1:3]
    dis = distance(x, y, w_x, w_y)
    reach_time = dis/500
    x, y = x + vx*reach_time, y + vy*reach_time
    x, y = math.ceil(x), math.ceil(y)
    
    # check is good to collide!
    # compare the vectors angle!
    b1_x, b1_y, b1_vx, b1_vy = entity[bludger_ids[0]][1:5]
    b2_x, b2_y, b2_vx, b2_vy = entity[bludger_ids[1]][1:5]
    
    # vector for destination
    v1_x, v1_y = x - b1_x, y - b1_y
    v2_x, v2_y = x - b2_x, y - b2_y
    
    # angle
    b1_dis = distance(0, 0, v1_x, v1_y)*distance(0, 0, b1_vx, b1_vy)
    b2_dis = distance(0, 0, v2_x, v2_y)*distance(0, 0, b2_vx, b2_vy)
    if b1_dis and b1_dis < 2000:
        b1_angle = math.acos(((v1_x*b1_vx) + (v1_y*b1_vy))/b1_dis)
    else:
        b1_angle = None
    if b2_dis and b1_dis < 2000:
        b2_angle = math.acos(((v2_x*b2_vx) + (v2_y*b2_vy))/b2_dis)
    else:
        b2_angle = None
    
    # b1_angle = None
    # b2_angle = None
    if b1_angle and b1_angle < 0.20:
        dis = distance(b1_x, b1_y, w_x, w_y)
        reach_time = dis/2000
        x, y = b1_x + b1_vx*reach_time, b1_y + b1_vy*reach_time
        x, y = math.ceil(x), math.ceil(y)
        print("bludgger bouncing 1", file=sys.stderr)
        print("MOVE {0} {1} {2} QUARK".format(x, y, thrust))
    elif b2_angle and b2_angle < 0.20:
        dis = distance(b2_x, b2_y, w_x, w_y)
        reach_time = dis/2000
        x, y = b2_x + b2_vx*reach_time, b2_y + b2_vy*reach_time
        x, y = math.ceil(x), math.ceil(y)
        print("bludgger bouncing 2", file=sys.stderr)
        print("MOVE {0} {1} {2} QUARK".format(x, y, thrust))
    else:
        x, y = rotate(entity, wizard_i, x, y, bludger_ids)
        print("MOVE {0} {1} {2} QUARK".format(x, y, thrust))
        
# throw to the place where no enemy and bludger is there
def throw(entity, wizard_i, bludger_ids, thrust=500):
    # get the information of the wizard throwing the snaffle
    # and the opponent wizards and bludgers
    w_x, w_y, vx, vy = entity[wizard_i][1:5]
    r = distance(w_x, w_y, *enemy_goal)
    w_vx, w_vy = ((enemy_goal[0] - w_x)/r)*thrust, ((enemy_goal[1] - w_y)/r)*thrust
    print("w_vx : {} w_vy : {}".format(w_vx, w_vy), file=sys.stderr)
    w_r = distance(0, 0, w_vx, w_vy)
    if w_r:
        print(w_vx, w_r, file=sys.stderr)
        w_theta = math.acos(w_vx/w_r)
    else:
        w_theta = 0
    
    e1_x, e1_y, e1_vx, e1_vy = entity[enemy_wizard[0]][1:5]
    e2_x, e2_y, e2_vx, e2_vy = entity[enemy_wizard[1]][1:5]
    b1_x, b1_y, b1_vx, b1_vy = entity[bludger_ids[0]][1:5]
    b2_x, b2_y, b2_vx, b2_vy = entity[bludger_ids[1]][1:5]
    
    best_sec = 0 
    best_theta = 0
    best_vx = 0
    best_vy = 0
    for theta in range(1, 22):
        offset = (math.pi/2)*(theta//2)*((-1)**theta)/10
        offset_theta = w_theta + offset
        offset_vx, offset_vy = math.cos(offset_theta)*w_r, math.sin(offset_theta)*w_r
        # ????????????????????????
        if w_vy < 0:
            offset_vy *= -1
        # print("offset : {} offset_vx: {} offset_vy : {}".format(offset, offset_vx, offset_vy), file=sys.stderr)
        if our_goal[0] == 0 and offset_vx < 0:
            continue
        elif our_goal[0] == 16000 and offset_vx > 0:
            continue
        
        # enemy wizard1, enemy wizard2, bludger1, bludger2
        # real_vx = (offset_vx + vx)*0.8
        # real_vy = (offset_vy + vy)*0.8
        # print(offset_vy, vy, file=sys.stderr)
        real_vx = offset_vx + vx*0.5
        real_vy = offset_vy + vy*0.5
        # print(real_vx, real_vy, file=sys.stderr)
        collide_sec = [100, 100, 100, 100]
        for sec in range(1, 26):
            sec *= 0.4
            e1_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              e1_x + e1_vx * sec,
                              e1_y + e1_vy * sec)
            e2_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              e2_x + e2_vx * sec,
                              e2_y + e2_vy * sec)
            b1_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              b1_x + b1_vx * sec,
                              b1_y + b1_vy * sec)
            b2_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              b2_x + b2_vx * sec,
                              b2_y + b2_vy * sec)
            if collide_sec[0] == 100 and e1_dis < 800:
               collide_sec[0] = sec 
            if collide_sec[1] == 100 and e2_dis < 800:
               collide_sec[1] = sec 
            if collide_sec[2] == 100 and b1_dis < 500:
               collide_sec[2] = sec 
            if collide_sec[3] == 100 and b2_dis < 500:
               collide_sec[3] = sec 
               
            # print("throw theta {}, collide {}".format(theta, collide_sec), file=sys.stderr)
        # which one collide the fastest?
        sec_result = min(collide_sec)
        
        # compare and update the info
        if sec_result > best_sec:
            best_sec = sec_result
            best_theta = offset_theta
            best_vx = offset_vx 
            best_vy = offset_vy
        if best_sec == 100:
            break
    
    x, y = w_x + (best_vx)*100, w_y + (best_vy)*100
    x, y = math.ceil(x), math.ceil(y)
    
    print("THROW {0} {1} {2}".format(x, y, thrust))
        
# throw to the place where no enemy and bludger is there
def spell(entity, snaffle_i, bludger_ids, magic=30):
    # get the information of the wizard throwing the snaffle
    # and the opponent wizards and bludgers
    w_x, w_y, vx, vy = entity[snaffle_i][1:5]
    r = distance(w_x, w_y, *enemy_goal)
    w_vx, w_vy = ((enemy_goal[0] - w_x)/r)*magic*50, ((enemy_goal[1] - w_y)/r)*magic*50
    print("w_vx : {} w_vy : {}".format(w_vx, w_vy), file=sys.stderr)
    w_r = distance(0, 0, w_vx, w_vy)
    if w_r:
        print(w_vx, w_r, file=sys.stderr)
        w_theta = math.acos(w_vx/w_r)
    else:
        w_theta = 0
    
    e1_x, e1_y, e1_vx, e1_vy = entity[enemy_wizard[0]][1:5]
    e2_x, e2_y, e2_vx, e2_vy = entity[enemy_wizard[1]][1:5]
    b1_x, b1_y, b1_vx, b1_vy = entity[bludger_ids[0]][1:5]
    b2_x, b2_y, b2_vx, b2_vy = entity[bludger_ids[1]][1:5]
    
    best_sec = 0 
    best_theta = 0
    best_vx = 0
    best_vy = 0
    for theta in range(1, 22):
        offset = (math.pi/2)*(((theta//2)*((-1)**theta)))/10
        offset_theta = w_theta + offset
        offset_vx, offset_vy = math.cos(offset_theta)*w_r, math.sin(offset_theta)*w_r
        # ????????????????????????
        if w_vy < 0:
            offset_vy *= -1
        print("offset : {} offset_vx: {} offset_vy : {}".format(offset, offset_vx, offset_vy), file=sys.stderr)
        if our_goal[0] == 0 and offset_vx < 0:
            continue
        elif our_goal[0] == 16000 and offset_vx > 0:
            continue
        
        # enemy wizard1, enemy wizard2, bludger1, bludger2
        collide_sec = [100, 100, 100, 100]
        real_vx = offset_vx + vx*0.5
        real_vy = offset_vy + vy*0.5
        for sec in range(1, 51):
            sec *= 0.2
            e1_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              e1_x + e1_vx * sec,
                              e1_y + e1_vy * sec)
            e2_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              e2_x + e2_vx * sec,
                              e2_y + e2_vy * sec)
            b1_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              b1_x + b1_vx * sec,
                              b1_y + b1_vy * sec)
            b2_dis = distance(w_x + real_vx * sec,
                              w_y + real_vy * sec,
                              b2_x + b2_vx * sec,
                              b2_y + b2_vy * sec)
            if collide_sec[0] == 100 and e1_dis < 1100:
               collide_sec[0] = sec 
            if collide_sec[1] == 100 and e2_dis < 1100:
               collide_sec[1] = sec 
            if collide_sec[2] == 100 and b1_dis < 500:
               collide_sec[2] = sec 
            if collide_sec[3] == 100 and b2_dis < 500:
               collide_sec[3] = sec 
               
            # print("spell theta {}, collide {}".format(theta, collide_sec), file=sys.stderr)
        # which one collide the fastest?
        sec_result = min(collide_sec)
        
        # compare and update the info
        if sec_result > best_sec:
            best_sec = sec_result
            best_theta = offset_theta
            best_vx = real_vx
            best_vy = real_vy
        if best_sec == 100:
            break
    
    x, y = w_x + best_vx*100, w_y + best_vy*100
    x, y = math.ceil(x), math.ceil(y)
    print("WINGARDIUM {0} {1} {2} {3}".format(snaffle_i, x, y, magic))
    
def attack_or_defense(entity, snaffle_ids, my_score, opponent_score):
    w1_x = entity[our_wizard[0]][1]
    w2_x = entity[our_wizard[1]][1]
    goal_x = our_goal[0]
    
    w1_dis = abs(goal_x - w1_x)
    w2_dis = abs(goal_x - w2_x)
    
    if w1_dis > w2_dis:
        std_dis = w2_x
    else:
        std_dis = w1_x
        
    our_snaffle = 0
    enemy_snaffle = 0
    for snaffle_i in snaffle_ids:
        snaffle_dis = abs(goal_x - entity[snaffle_i][1])
        if snaffle_dis > std_dis:
            our_snaffle += 1
        else:
            enemy_snaffle += 1
            
    if our_snaffle + my_score >= enemy_snaffle + opponent_score:
        return 'attack'
    else:
        return 'defense'

# game loop
while True:
    my_score, my_magic = [int(i) for i in input().split()]
    opponent_score, opponent_magic = [int(i) for i in input().split()]
    entities = int(input())  # number of entities still in game
    
    # entity information
    entity = {}
    snaffle_ids = []
    bludger_ids = []
    snaffle_num = 0
    for i in range(entities):
        # entity_id: entity identifier
        # entity_type: "WIZARD", "OPPONENT_WIZARD" or "SNAFFLE" or "BLUDGER"
        # x: position
        # y: position
        # vx: velocity
        # vy: velocity
        # state: 1 if the wizard is holding a Snaffle, 0 otherwise. 1 if the Snaffle is being held, 0 otherwise. id of the last victim of the bludger.
        entity_id, entity_type, x, y, vx, vy, state = input().split()
        entity_id = int(entity_id)
        x = int(x)
        y = int(y)
        vx = int(vx)
        vy = int(vy)
        state = int(state)
        entity[entity_id] = [entity_type, x, y, vx, vy, state]
        
        # count snaffle number
        if entity_type == "SNAFFLE":
            snaffle_num += 1
            snaffle_ids.append(entity_id)
        
        if entity_type == "BLUDGER":
            bludger_ids.append(entity_id)
    
    # Check the information stored
    # for i in range(len(entity)):
    #     print(entity[i], file=sys.stderr)
    # print(snaffle_num, file=sys.stderr)
    
    # get snaffle information 
    snaffle_info = calculate_snaffle(entity, snaffle_num)
    
    # attack and defense position
    wizard_position = calculate_wizard_position(entity)
    
    # choose attack of defence
    order = attack_or_defense(entity, snaffle_ids, my_score, opponent_score)
    
    for wizard_i in our_wizard:
        wizard = entity[wizard_i]
        enemy_wizard_1, enemy_wizard_2 = entity[enemy_wizard[0]], entity[enemy_wizard[1]]
        if my_magic > 30:
            # apply the magic to the snaffle
            if order == 'attack':
                spell(entity, snaffle_info['enemy_snaffle'], bludger_ids, magic=30)
            elif order == 'defense':
                spell(entity, snaffle_info['our_snaffle'], bludger_ids, magic=30)
            continue
        
        # if it has a snaffle just throw it to the goal
        if wizard[5]:
            throw(entity, wizard_i, bludger_ids, thrust=500)
            continue

        # FORCE ATTACK!
        if True or order == 'attack':
        # if order == 'attack':
            # attack
            snaffle = entity[snaffle_info['wizard_{}'.format(wizard_i)]]
            move(entity, bludger_ids, wizard_i, snaffle, thrust=150)
        elif order == 'defense':
            # defense
            if wizard_i == wizard_position['attack']:
                snaffle = entity[snaffle_info['wizard_{}'.format(wizard_i)]]
                move(entity, bludger_ids, wizard_i, snaffle, thrust=150)
            else:
                if snaffle_info['our_snaffle'] == snaffle_info['wizard_{}'.format(wizard_position['attack'])]:
                    snaffle = entity[snaffle_info['wizard_{}'.format(wizard_i)]]
                else:
                    snaffle = entity[snaffle_info['our_snaffle']]
                move(entity, bludger_ids, wizard_i, snaffle, thrust=150)
    
