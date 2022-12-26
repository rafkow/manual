# this is coment 
FROM alpine

# become exec reference path curent workink dir
WORKDIR /usr/app 

COPY [FROM] [TO]

COPY ./ ./
COPY . .

RUN apk add --update redis
RUN npm install

CMD ["redis-server"]
CMD ["npm", "start"]